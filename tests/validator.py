#!/usr/bin/env python

import yaml
from yaml.loader import SafeLoader

import os
os.system('color')
import pathlib

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    ERROR = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

import pathlib

class PropertyValidator:
	def __init__(self):
		self.type = 'str'
		self.required = True
		self.dependency = ''
		pass

class SpecifierValidatorBase:
	def __init__(self):
		self.required_properties = [
			'name',
			'group',
			'position',
			'type',
			'group'
		]

		self.allowed_properties = [
			'subgroup',
			'comment',
			'samples',
			'type-comment',
			'documentation',
			'examples',
			'images',
			'source',
			'keywords',
			'links',
			'required',
			'related',
			'incompatible',
			'synonyms',
			'antonyms',
			'deprecated',
			'version',
		]
		for val in self.required_properties:
			self.allowed_properties.append(val)
	
		self.valid_types = [
			'flag',
			'string',
			'bool',
			'integer',
			'number',
			'float',
		]

		self.valid_positions = [
			'main',
			'meta',
		]

		self.reference_fields = [
			'required',
			'related',
			'incompatible',
			'synonyms',
			'antonyms',
			'implies',
		]

		self.ids = []

	def should_run(self, filename: str) -> bool:
		return False

	def get_identifier(self, entry) -> str:
		for req in self.required_properties:
			if req in entry:
				return f"{entry[req]}"
		return '[unknown]'

	def validate_file(self, data_file):
		print(f"{bcolors.HEADER}Validating {data_file}{bcolors.ENDC}")

		with open(data_file, encoding='utf8') as f:

			data = yaml.load(f, Loader=SafeLoader)

			total_specifiers = 0
			with_errors = 0
			with_warnings = 0
			total_errors = 0
			total_warnings = 0
			if 'specifiers' in data:
				print(f"YAML Loaded, {len(data['specifiers'])} entries to validate")

				# gather ids
				for entry in data['specifiers']:
					if 'name' in entry:
						id = entry['name'].lower()
						if id in self.ids:
							print(f"Not unique ID")
						else:
							self.ids.append(id)

				for entry in data['specifiers']:
					errors, warnings = self.validate_entry(entry)

					# Per-entry summary
					total_errors += len(errors)
					total_warnings += len(warnings)

					if len(errors) > 0:
						with_errors += 1
					if len(warnings) > 0:
						with_warnings += 1

					id = self.get_identifier(entry)

					if len(errors) > 0 or len(warnings) > 0:
						print(f"Entry #{total_specifiers} '{id}':")
						for error in errors:
							print(f" - {bcolors.ERROR}Error{bcolors.ENDC}   - {error}")
						for warn in warnings:
							print(f" - {bcolors.WARNING}Warning{bcolors.ENDC} - {warn}")
						print("")
					total_specifiers += 1
			else:
				print("Fail")
			
			print(f"{total_specifiers} processed, {bcolors.ERROR}{with_errors} with errors{bcolors.ENDC}, {bcolors.WARNING}{with_warnings} with warnings{bcolors.ENDC}")
		print("\n====================================\n")

	def validate_entry(self, entry):
		errors = []
		warnings = []

		for req in self.required_properties:
			if not req in entry:
				errors.append(f"Missing required field '{req}'")

		if 'type' in entry:
			if entry['type'] not in self.valid_types:
				errors.append(f"Type value is invalid '{entry['type']}'")

		if 'position' in entry:
			if entry['position'] not in self.valid_positions:
				errors.append(f"Position value is invalid '{entry['position']}'")
		
		for ref_field in self.reference_fields:
			if ref_field in entry:
				for ref_value in entry[ref_field]:
					lowered_id = ref_value.lower()

					# split into class and property
					if '.' in lowered_id:
						page, property = lowered_id.split('.')

					if lowered_id not in self.ids:
						errors.append(f"Field '{ref_field}' referenced non-existant id '{lowered_id}'")
		
		for key, value in entry.items():
			if not key in self.allowed_properties:
				warnings.append(f"Unknown key '{key}'")
		
		return errors, warnings

	def validate():
		pass


class UClassValidator(SpecifierValidatorBase):
	def __init__(self):
		super().__init__()
		self.allowed_properties.append('inherited')

	def should_run(self, filename: str):
		return filename.endswith('uclass.yml')

	def validate(self, entry):
		errors, warnings = super().validate_entry(entry)


class UDefaultValidator(SpecifierValidatorBase):
	def __init__(self, filename):
		super().__init__()
		self.filename = filename

	def should_run(self, filename: str):
		return filename.endswith(self.filename)


class UFunctionValidator(SpecifierValidatorBase):
	def __init__(self):
		super().__init__()
		self.allowed_properties.append('implies')

	def should_run(self, filename: str):
		return filename.endswith('ufunction.yml')


class UPropertyValidator(SpecifierValidatorBase):
	def __init__(self):
		super().__init__()
		self.allowed_properties.append('implies')

	def should_run(self, filename: str):
		return filename.endswith('uproperty.yml')

current_directory = pathlib.Path(__file__).parent.resolve()

yaml_files_path = current_directory / '../yaml/'
all_files = os.listdir(yaml_files_path)

validators = [
	UDefaultValidator('uenum.yml'),
	UClassValidator(),
	UFunctionValidator(),
	UPropertyValidator(),
	UDefaultValidator('uinterface.yml'),
	UDefaultValidator('umeta.yml'),
	UDefaultValidator('uparam.yml'),
	UDefaultValidator('ustruct.yml'),
]

for file in all_files:
	for validator in validators:
		if validator.should_run(file):
			validator.validate_file(yaml_files_path / file)


# data = None
# with open(data_file, encoding='utf8') as f:
# 	data = yaml.load(f, Loader=SafeLoader)
# 
# seen_ids = {}
# total_errors = 0
# total_warnings = 0
# 
# data = data['specifiers']
# 
# count = len(data)
# i = 1
# for entry in data:
# 	errors = []
# 	warnings = []
# 
# 
# print(f"{count} processed")
# 
# print(f"{bcolors.ERROR}Errors:{bcolors.ENDC}     - {total_errors}")
# print(f"{bcolors.WARNING}Warnings:{bcolors.ENDC}   - {total_warnings}")
# 
# if total_errors == 0 and total_warnings == 0:
# 	print(f"{bcolors.OKGREEN}Success!{bcolors.ENDC}")
