#!/usr/bin/env python

import yaml
from yaml.loader import SafeLoader

import os
os.system('color')
from pathlib import Path
from glob import glob

import re

starts_with_uppercase_regex = re.compile('^[A-Z]')

glob_search = f"./**/*.yml"
all_files = glob(glob_search, recursive=True)

class IdLookup(): 
	def __init__(self, files: list[str]):
		self.found_stuff: map[str,set[str]] = {}

		for file in files:
			if file.endswith('.yml'):
				with open(file, encoding='utf8') as f:
					data = yaml.load(f, Loader=SafeLoader)
					if 'id' in data:
						id = data['id'].lower()
						if id in self.found_stuff:
							print("Non-unique id")
						self.found_stuff[id] = set()

						# gather ids
						if 'specifiers' in data:
							# gather ids
							for entry in data['specifiers']:
								if 'name' in entry:
									property_name = entry['name'].lower()
									if property_name in self.found_stuff[id]:
										print(f"Duplicate property name {property_name}")
									self.found_stuff[id].add(property_name)
									if not property_name in self.found_stuff[id]:
										print("NOT FOUND")

	def has_key(self, raw_key: str, current_page: str) -> bool:
		property = raw_key.lower()

		page_to_search = current_page
		# split into class and property
		if '.' in property:
			page, property = property.split('.')
			page_to_search = page

		if page_to_search in self.found_stuff:
			if not property in self.found_stuff[page_to_search]:
				#print(f"Property {raw_key} not found in page {page_to_search}")
				#print(self.found_stuff[page_to_search])
				return False
		else:
			#print(f"Property {raw_key} refers to unknown page {page_to_search}")
			return False
		return True

id_lookup = IdLookup(all_files)

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

class PropertyValidator:
	def __init__(self):
		self.type = 'str'
		self.required = True
		self.dependency = ''
		pass

class SpecifierValidatorBase:
	def __init__(self):
		self.properties = [
			{ 'name': 'name', 'required': True, 'datatype': str },
			{ 'name': 'group', 'required': True, 'datatype': str  },
			{ 'name': 'position', 'required': True, 'datatype': str },
			{ 'name': 'type', 'required': True, 'datatype': str },
			{ 'name': 'group' , 'required': True, 'datatype': str }
			{ 'name': 'subgroup', 'required': False, 'datatype': str },
			{ 'name': 'comment', 'required': False, 'datatype': str },
			{ 'name': 'samples', 'required': False, 'datatype': list[str] },
			{ 'name': 'type-comment', 'required': False, 'datatype': str },
			{ 'name': 'documentation', 'required': False, 'datatype': str },
			{ 'name': 'examples', 'required': False, 'datatype': list[str] },
			{ 'name': 'images', 'required': False, 'datatype': list[str] },
			{ 'name': 'keywords', 'required': False, 'datatype': list[str] },
			{ 'name': 'links', 'required': False, 'datatype': list[str] },
			{ 'name': 'required', 'required': False, 'datatype': list[str] },
			{ 'name': 'related', 'required': False, 'datatype': list[str] },
			{ 'name': 'incompatible', 'required': False, 'datatype': list[str] },
			{ 'name': 'synonyms', 'required': False, 'datatype': list[str] },
			{ 'name': 'antonyms', 'required': False, 'datatype': list[str] },
			{ 'name': 'deprecated', 'required': False, 'datatype': True },
			{ 'name': 'version', 'required': False, 'datatype': str },
			{ 'name': 'utility', 'required': False, 'datatype': int }
		]

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
			'keywords',
			'links',
			'required',
			'related',
			'incompatible',
			'synonyms',
			'antonyms',
			'deprecated',
			'version',
			'utility',
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

	def should_run(self, filename: str) -> bool:
		return False

	# returns the first valid required field so we can have something hopefully unique to refer
	# to this entry by
	def get_identifier(self, entry) -> str:
		for req in self.required_properties:
			if req in entry:
				return f"{entry[req]}"
		return '[unknown]'

	def validate_file(self, data_file: str) -> None:
		print(f"{bcolors.HEADER}Validating {data_file}{bcolors.ENDC}")

		with open(data_file, encoding='utf8') as f:

			data = yaml.load(f, Loader=SafeLoader)

			total_specifiers: int = 0
			with_errors: int = 0
			with_warnings: int = 0
			total_errors: int = 0
			total_warnings: int = 0
			this_page_id = ''

			if not 'id' in data:
				errors.append(f"Does not have {id} property")
			else:
				this_page_id = data['id']

			if 'specifiers' in data:
				print(f"YAML Loaded, {len(data['specifiers'])} entries to validate")


				for entry in data['specifiers']:
					errors, warnings = self.validate_entry(entry=entry, this_page_id=this_page_id)

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
				print("Fail, does not have specifiers property")
			
			print(f"{total_specifiers} processed, {bcolors.ERROR}{with_errors} with errors{bcolors.ENDC}, {bcolors.WARNING}{with_warnings} with warnings{bcolors.ENDC}")
		print("\n====================================\n")

	def validate_entry(self, entry, this_page_id: str) -> tuple[list[str], list[str]]:
		errors: list[str] = []
		warnings: list[str] = []

		for req in self.required_properties:
			if not req in entry:
				errors.append(f"Missing required field '{req}'")

		if 'type' in entry:
			if entry['type'] not in self.valid_types:
				errors.append(f"Type value is invalid '{entry['type']}'")

		if 'position' in entry:
			if entry['position'] not in self.valid_positions:
				errors.append(f"Position value is invalid '{entry['position']}'")
		
		name_errors, name_warnings = self.validate_name(entry['name'])
		errors.append(name_errors)
		warnings.append(name_warnings)
		
		for ref_field in self.reference_fields:
			if ref_field in entry:
				for ref_value in entry[ref_field]:
					if not id_lookup.has_key(ref_value, this_page_id):
						errors.append(f"Field '{ref_field}' referenced non-existant id '{ref_value}'")
		
		for key, value in entry.items():
			if not key in self.allowed_properties:
				warnings.append(f"Unknown key '{key}'")
		
		return errors, warnings

	def validate_name(self, name: str) -> tuple[list[str], list[str]]:
		errors: list[str] = []
		warnings: list[str] = []

		if not re.match(starts_with_uppercase_regex, name):
			warnings.append(f"Field name {name} does not start with an uppercase letter.")
		
		return errors, warnings


class UDefaultValidator(SpecifierValidatorBase):
	def __init__(self, filename: str):
		super().__init__()
		self.filename = filename

	def should_run(self, filename: str) -> bool:
		return filename.endswith(self.filename)


class UClassValidator(SpecifierValidatorBase):
	def __init__(self):
		super().__init__()
		self.allowed_properties.append('inherited')

	def should_run(self, filename: str) -> bool:
		return filename.endswith('uclass.yml')


class UFunctionValidator(SpecifierValidatorBase):
	def __init__(self):
		super().__init__()
		self.allowed_properties.append('implies')

	def should_run(self, filename: str) -> bool:
		return filename.endswith('ufunction.yml')


class UPropertyValidator(SpecifierValidatorBase):
	def __init__(self):
		super().__init__()
		self.allowed_properties.append('implies')

	def should_run(self, filename: str) -> bool:
		return filename.endswith('uproperty.yml')

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
			validator.validate_file(file)
