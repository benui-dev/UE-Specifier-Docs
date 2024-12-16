# Unreal Engine Specifiers

This repo contains the YAML files and images used to generate the property
specifier documentation pages on [benui.ca](https://benui.ca):

* [`UPROPERTY`](https://benui.ca/unreal/uproperty/)
* [`UFUNCTION`](https://benui.ca/unreal/ufunction/)
* [`UPARAM`](https://benui.ca/unreal/uparam/)
* [`UCLASS`](https://benui.ca/unreal/uclass/)
* [`USTRUCT`](https://benui.ca/unreal/ustruct/)
* [`UENUM` and `UMETA`](https://benui.ca/unreal/uenum-umeta/)

I've made them open-source so people can submit pull requests, make forks,
or publish their own versions of the documentation.

Example entry:
```yaml
- name: VisibleAnywhere
  group: Editor
  subgroup: Visibility
  position: main
  type: flag
  utility: 3
  incompatible: [ VisibleDefaultsOnly, VisibleInstanceOnly, EditAnywhere, EditDefaultsOnly, EditInstanceOnly ]
  comment:
    Properties marked with `VisibleAnywhere` are visible in the both Details Panel of Blueprint assets and the Details Panel of Blueprint instances within maps.
    
    Note that this refers to being visible in the *Details Panel*, not visible in the *Blueprint Graph*. For that you need to use `BlueprintReadOnly`.
  samples:
    - |
      UPROPERTY(VisibleAnywhere)
      int32 VisibleAnywhereNumber;
  documentation:
    text: Indicates that this property is visible in all property windows, but cannot be edited. This Specifier is incompatible with the "Edit" Specifiers.
    source: https://dev.epicgames.com/documentation/en-us/unreal-engine/property-specifiers
  images: [ /assets/unreal/uproperty/visibility-defaults-selected.png, /assets/unreal/uproperty/visibility-instance-selected.jpg ]
```

## Format Description

* I try to keep the `comment` field less like strict documentation and more
  tutorial-like; talking about why you'd want to use the specifier and
  potential edge-cases. 

| Property Name | Data Type | Required? | Notes |
| --- | --- | --- | --- |
| `name` | string | Required | Plain text. I try to camelcase even though the name is technically case-insensitive. |
| `group` | string | | Arbitrary string I use to display related specifiers together. |
| `subgroup` | string | Requires `group` | A way of categorizing specifiers further within a group. |
| `position` | string | Required | Valid values are `main` or `meta`. |
| `utility` | integer | | Value between 1-3. 3 is for extremely-commonly-used specifiers, 1 is for niche or rarely-used specifiers.  |
| `type` | string | Required | Valid values are `flag`, `string`, `number`, `bool`, `integer`. |
| `type-comment` | string | Requires `type` | Extra information about the type. For example if the `string` must be the name of a valid `UPROPERTY` member variable, or `number` must be an integer. |
| `comment` | string | | Long free-text description on how to use the specifier. Includes Markdown formatting. |
| `samples` | string array | | An array of code snippets that show how the specifier is used. |
| `required` | specifier array | | A list of specifiers that **must be included** for this specifier to be valid. See note below on specifier IDs. |
| `related` | specifier array | | Other specifiers that are worth looking at related to this context. |
| `incompatible` | specifier array | | A list of specifiers that are invalid when paired with this specifier. |
| `synonyms` | specifier array | | A list of specifiers that have the **same effect** to this specifier. |
| `antonyms` | specifier array | | A list of specifiers that have the **opposite effect** to this specifier. |
| `inherited` | boolean | | `UCLASS`-specific. Whether a specifier on a parent means the child implicitly has that same specifier. If no value is defined, interpret as 'false'. True is just the string 'true'. |
| `documentation` | struct | | See below for the properties within this struct. |
| `documentation.text` | text | Required if `documentation` struct exists. | Official Unreal Engine documentation that describes the specifier. Can be taken from web or source code. |
| `documentation.source` | url | | The URL from which the documentation is taken. In the case of files I include a link to the file on GitHub. |
| `images` | string array | | I try to take screenshots with Unreal Engine 5.0 for consistency. See existing documentation for relative path. |

**Specifier IDs:** For the purpose of cross-linking between specifier documents, 
* The `EditInline` property in `UProperty` has a `related` entry `UClass.EditInlineNew`

## Tests

* Validate changes to the yaml files with `tests/validator.py`

## Example Project

There is an Unreal Engine project located in `/Example/`. The code is partly there as reference, partly for generating screenshots for the site. Take a look if you like!


## Issues

Please [submit Issues](https://github.com/benui-dev/UE-Specifier-Docs/issues) cases of missing specifiers or mistakes in the documentation.


## Known Issues

* Some specifiers are not yet categorized. They're listed under a `TODO` category.
* Some specifiers have no code samples or comments.
* Some specifiers have no screenshots.


## License

See License file
