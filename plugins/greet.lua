-- mod-version:3
-- Example Lua plugin that makes use of the native sample plugin.
local core = require "core"
local sample = require "libraries.sample"

core.log("%s", sample.greet("John"))
