# Lite XL Sample Native Plugin

This repository provides a working skeleton that you can use as a base to build
and share your own native plugins. Clone this repository, make any necessary
changes and publish it to a GitHub repository of your own. Make sure to enable
GitHub Actions, then go to Actions -> Release and hit: `Run workflow` to let
GitHub build a binary for you.

Some of the files that you will find on this repo are:

* manifest.json - Used by lpm (the Lite XL package manager) for automated
  installation.
* .github/workflows/release.yml - Commands to let GitHub Actions automatically
  build a binary.
* changelog.md - Read by GitHub Actions to make a release, always a good idea
  to keep this updated.
* lite_xl_plugin_api.h - Used to optionally import Lua symbols directly from
  the running Lite XL instance. Latest version of this file is found on
  https://github.com/lite-xl/lite-xl/blob/master/resources/lite_xl_plugin_api.h

## Building

You will need to have meson and a working build environment for your operating
system. Then, to build just execute the following commands:

```sh
meson setup build
meson compile -C build
```

By default we configured meson to download Lua and statically link
to it. To disable this behavior and instead link against system libraries,
use `--wrap-mode default`

```sh
meson setup --wrap-mode default build
```

Also you can link to LuaJIT instead by adding `-Djit=true`

```sh
meson setup -Djit=true build
```

If you want to use the same Lua that Lite XL is linked against, and skip
the step of linking to a Lua lib, use `-Duse_lua=disabled`. This will
use the `lite_xl_plugin_api.h` header to import the required symbols:

```sh
meson setup -Duse_lua=disabled build
```

## Installation

To install just copy the generated library file to your libraries directory:

```sh
cp build/sample.so ~/.config/lite-xl/libraries/
```

Then install the Lua plugin that makes use of the native sample plugin:

```sh
cp plugins/greet.lua ~/.config/lite-xl/plugins/
```
