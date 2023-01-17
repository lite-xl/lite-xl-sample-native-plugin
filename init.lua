-- mod-version:3
-- Example Lua plugin that makes use of the native sample plugin.
local core = require "core"
local sample = require "plugins.sample.native"

core.log("%s", sample.greet("John"))
