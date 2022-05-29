# Unreal Engine Specifiers

This repo contains the YAML files and images used to generate the property
specifier documentation pages on [benui.ca](https://benui.ca):

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

* I try to keep the `comment` field less like strict documentation and more
  tutorial-like; talking about why you'd want to use the specifier and
  potential edge-cases. 

| Property Name | Data Type | Required? | Notes |
| --- | --- | --- | --- |
| `name` | string | Required | Plain text. I try to camelcase even though the name is technically case-insensitive. |
| `group` | string | | Arbitrary string I use to display related specifiers together. |
| `subgroup` | string | | A way of categorizing specifiers further within a group. |
| `position` | string | Required | Valid values are `main` or `meta`. |
| `type` | string | Required | Valid values are `flag`, `string`, `number`, `bool`. |
| `type-comment` | string | | Extra information about the type. For example if the `string` must be the name of a valid `UPROPERTY` member variable, or `number` must be an integer. |
| `comment` | string | | Long free-text description on how to use the specifier. Includes Markdown formatting. |
| `samples` | string array | | An array of code snippets that show how the specifier is used. |
| `required` | specifier array | | A list of specifiers that must be included for this specifier to be valid. |
| `related` | specifier array | | Other specifiers that are worth looking at related to this context. |
| `incompatible` | specifier array | | A list of specifiers that are invalid when paired with this specifier. |
| `synonyms` | specifier array | | A list of specifiers that have the **same effect** to this specifier. |
| `antonyms` | specifier array | | A list of specifiers that have the **opposite effect** to this specifier. |
| `inherited` | boolean | | `UCLASS`-specific. Whether a specifier on a parent means the child implicitly has that same specifier. |
| `documentation` | struct | | See below for the properties within this struct. |
| `documentation.text` | text | Required if `documentation` struct exists. | Official Unreal Engine documentation that describes the specifier. Can be taken from web or source code. |
| `documentation.source` | url | | The URL from which the documentation is taken. In the case of files I include a link to the file on GitHub. |
| `images` | string array | | I try to take screenshots with Unreal Engine 5.0 for consistency. |


## Known Issues

* Some specifiers are not yet categorized. They're listed under a `TODO` category.
* Some specifiers have no code samples or comments.

## License

CC0-1.0
