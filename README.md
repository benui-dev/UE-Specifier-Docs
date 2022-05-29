# Unreal Engine Specifiers

This repo contains the YAML files used to generate the property specifier
documentation pages on [benui.ca](https://benui.ca):

* [UPROPERTY()](https://benui.ca/unreal/uproperty/)
* [UFUNCTION()](https://benui.ca/unreal/ufunction/)
* [UPARAM()](https://benui.ca/unreal/uparam/)
* [UCLASS()](https://benui.ca/unreal/uclass/)
* [USTRUCT()](https://benui.ca/unreal/ustruct/)
* [UENUM() and UMETA()](https://benui.ca/unreal/uenum-umeta/)

I've made them open-source so people can submit pull requests, make forks,
publish their own versions of the documentation.

Example entry:
```yaml
- name: VisibleAnywhere
  group: Editor
  subgroup: Visibility
  position: main
  type: flag
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
    source: https://docs.unrealengine.com/4.27/en-US/ProgrammingAndScripting/GameplayArchitecture/Properties/Specifiers/
  images: [ /assets/unreal/uproperty/visibility-defaults-selected.png, /assets/unreal/uproperty/visibility-instance-selected.jpg ]
```
## Format Description

| Property Name | Data Type | Required? | Example | Notes |
| --- | --- | --- | --- | --- |
| `name` | string | Required | VisibleAnywhere | Plain text. I try to camelcase even though the name is technically case-insensitive. |
| `group` | string |  | Editor | Arbitrary string I use to display related specifiers together. |
| `subgroup` | string |  | Visibility | Optional further |
| `position` | string | Required | main | Valid values are `main` or `meta`. |
| `type` | string | Required | Visibility | Valid values are `flag`, `string`, `number`, `bool`. |
| `comment` | string |  | | Long free-text description on how to use the specifier. Includes Markdown formatting. |
| `samples` | string array |  |  | An array of code snippets that show how the specifier is used. |
| `incompatible` | string array |  | Visibility | A list of specifiers that are invalid when paired with this specifier. |
| `antonyms` | string array |  | Visibility | A list of specifiers that have the opposite effect to this specifier. |
| `documentation` | struct  |  | Visibility | |
| `documentation.text` | text  |  |  | Official Unreal Engine documentation that describes the specifier. Can be taken from web or source code. |
| `documentation.source` | url  |  |  | The URL from which the documentation is taken. |
| `images` | string array |  | /assets/unreal/uproperty/visibility-defaults-selected.png | Optional further |

## Notes on Format

* Most text fields like `comment` use Markdown formatting.

## Known Issues

* Some specifiers are not yet categorized. They're listed under a `TODO` category.
* Some specifiers have no code samples or comments.
* Some text fields have hardcoded links to my site, I'll fix that soon.
* Some fields are a mix of singular and plural (e.g. `sample` and `samples`). I just fixed my parser to allow both, but I'll fix the data to be all plural.

## License

CC0-1.0
