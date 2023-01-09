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
* lite_xl_plugin_api.h - Used to import Lua symbols directly from
  the running Lite XL instance. Latest version of this file is found on
  https://github.com/lite-xl/lite-xl/blob/master/resources/lite_xl_plugin_api.h

## Building

You will need to have meson and a working build environment for your operating
system. Then, to build just execute the following commands:

```sh
meson setup build
meson compile -C build
```

**(Not Recommended)** If you do not want to use the same Lua linked to Lite XL,
use `-Duse_lua=enabled`. This will link with the system lua skipping the
use of `lite_xl_plugin_api.h` header and not importing the required symbols
directly from Lite XL:

```sh
meson setup -Duse_lua=enabled build
```

**Notice**: the `subprojects` directory contains a `lua` and `luajit`
meson wraps. These are used in case you decide to not depend on
`lite_xl_plugin_api.h` for lua symbols importing, and your system does not
has the targeted lua runtime installed. In this case it will download the
runtime, compile it and statically link to it. Also you can force using the
meson wraps by using the flag `--wrap-mode forcefallback`:

```sh
meson setup --wrap-mode forcefallback build
```

Also you can try and link against LuaJIT for testing purposes
by adding `-Djit=true`:

```sh
meson setup -Djit=true build
```

## Installation

To install just copy the generated native library file to your plugins directory:

```sh
mkdir -p ~/.config/lite-xl/plugins/sample
cp build/native.so ~/.config/lite-xl/plugins/sample/
```

Then install the Lua part of the plugin:

```sh
cp init.lua ~/.config/lite-xl/plugins/sample/
```
