#!/usr/bin/env python

# This is a fairly janky script designed to find all specifiers in the Unreal source.
# It does it by regexing lines that match UPROPERTY etc.
# It then goes through the string

import yaml
from yaml.loader import SafeLoader

import os
os.system('color')
import pathlib
import glob
import argparse

import re

class Specifier:
	key: str
	value: str
	is_meta: bool = False

	def __init__(self, key, value):
		self.key = key
		self.value = value
	
	def __str__(self):
		return f"{self.key}={self.value}"

def string_to_specifiers(input: str) -> list[Specifier]:
	buf: str = ''
	current_key: str = ''
	current_value: str = ''
	in_quote: bool = False
	in_value: bool = False

	specifiers: list[Specifier] = []

	for char in input:
		if char == '"':
			in_quote = not in_quote

		elif char == ',':
			if in_quote:
				buf += char
			else:
				if in_value:
					current_value = buf
				else:
					current_key = buf
				specifiers.append(Specifier(current_key, current_value))
				# start a new something
				current_key = ''
				current_value = ''
				in_value = False
				buf = ''

		elif char == '=':
			current_key = buf
			in_value = True
			buf = ''

		elif char == ' ':
			if in_quote:
				buf += char
		else:
			buf += char

		print(f"Char: {char}, buf: {buf}, current_key: {current_key}, current_value: {current_value}")
	
	if in_value:
		current_value = buf
	else:
		current_key = buf
	specifiers.append(Specifier(current_key, current_value))

	return specifiers
		
import pprint


res = string_to_specifiers('cake, beans=hello, wha="test"')
for r in res:
	print(r)
pprint.pp(res)

exit()


scraper = argparse.ArgumentParser(description="Merges a bunch of JSON files into a single file.")
scraper.add_argument('-u', '--unreal', dest='unreal_path', type=pathlib.Path, help='Path to Unreal source', default='C:/UE_5.5/Engine/Source')
scraper.add_argument('-y', '--yaml_dir', dest='yaml_path', type=pathlib.Path, help='Path to existing specifiers directory', default='../yaml')

args = scraper.parse_args()

uprop_regex = re.compile("\s*UPROPERTY\((.*)\)?")
meta_regex = re.compile("meta\s*\=\s*\((.*)\)?")

specifier_to_example = {}

if os.path.isdir(args.unreal_path):
	glob_search = f"{args.unreal_path}/**/*.h"
	all_files = glob.iglob(glob_search, recursive=True)

	for file in all_files:
		with open(file, 'r') as input_handle:
			for line in input_handle:
				results = uprop_regex.search(line)
				if results:
					print(results.group(1))
					specifier_contents = results.group(1)
					meta_results = meta_regex.search(specifier_contents)

					# Want to split stuff w/o using regex

else:
	print(f"Unreal dir is not dir {args.unreal_path}")
