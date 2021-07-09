# pipex

## Overview

Reproduced the shell's pipe.

## Usage

```
git clone https://github.com/kotabrog/pipex.git
cd pipex
make
```

For example, if you run the following, 

```
./pipex Makefile cat grep clean file
```

it will be the same as the following.

```
< Makefile cat | grep clean > file
```

In addition, multiple commands can be given.

```
./pipex Makefile cat cat cat cat cat cat cat cat file
```

## Author

[twiter](https://twitter.com/Kotabrog)

## Licence

[MIT](https://github.com/kotabrog/pipex/blob/main/LICENSE)
