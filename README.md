# fixme - a simple FIX 4.2 server

Sadly, this FIX server is incomplete, but it can receive and parse messages
already and it has already export the API of the unfinished market core.

## Dependencies

 - CMake (for build)
 - c++14 compiler (This project makes heavy use of modern c++ features)
 - Boost.Asio (Network)
 - Boost.Progam_options (Parse INI-like config file)

## Function and Features

 - A simple TCP server that receive FIX 4.2 messages.
 - Fully parse FIX 4.2 messages and log them to stdout.
 - Detect error on FIX 4.2 messages.
 - Extensible. Interface of market core is already designed and exported. (See
   `market.cpp`)

## How to test the project

You should build fixme first.

```sh
cd test
dir/to/fixme -c anyhost2333.conf & # You may also run fixme in another terminal
python gen.py < testmsg.asc > testmsg.fix
netcat ::1 2333 < testmsg.fix      # Watch the output
netcat ::1 2333 < anything_invalid # of fixme
```

## About the project

Copyright (C) 2016 Zheng Lv <lv.zheng.2015@gmail.com>

This project is finished with guidance from Morgan Stanley, Shanghai.

You can get the latest code at https://github.com/lv-zheng/fixme
