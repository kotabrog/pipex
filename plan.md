# plan

## 仕様
- 実行ファイル名はpipex
- 仕様関数
  - access
  - open
  - unlink
  - close
  - read
  - write
  - malloc
  - waitpid
  - wait
  - free
  - pipe
  - dup
  - dip2
  - execve
  - fork
  - perror
  - strerror
  - exit
- ./pipex file1 cmd1 cmd2 file2 は < file1 cmd1 | cmd2 > file2 として解釈できるようにする
- file1, file2はファイル名、cmd1, cmd2は引数を含めたコマンド（一つの引数としてそれぞれ与えられる）
- bonus
  - 多段パイプ
  - ./pipex here_doc LIMITER cmd cmd1 file でcmd << LIMITER | cmd1 >> fileと解釈
