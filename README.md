# my_ls

You must recode the **ls [-alRdrt] [FILE]** command.
Options can be given in either order:

```text
∼/B-PSU-100> ./my_ls -l -t
...
∼/B-PSU-100> ./my_ls -lRt
...
∼/B-PSU-100> ./my_ls -lt -R -t
```

It must be possible to pass a list of files/folders as parameters:

```text
∼/B-PSU-100> ./my_ls -l /dev /usr/sbin
...
∼/B-PSU-100> ./my_ls -l -r file1 file
...
```

```text
Handling the column formatting without the -l option would be
considered as a bonus point, as well as sorting and coloring.
```

As a bonus, you could also handle others options, such as -uFgf.

## AUTHORIZED FUNCTIONS

The only system calls allowed are the following ones:

- opendir, readdir, closedir, stat, lstat, write,
- getpwuid, getgrgid, time, ctime, readlink,
- va_start, va_arg, va_end,
- malloc, free, perror, strerror, exit.

## EXAMPLES

```text
∼/B-PSU-100> ./my_ls -l -R
.:
total 156
drwxr-xr-x 2 theo theo 4096 Nov 9 15:31 dir
-rwxr-xr-x 1 theo theo 151352 Nov 30 14:32 my_ls
-rw-r–r– 1 theo theo 0 Nov 9 15:30 ‘#test#’
-rw-r–r– 1 theo theo 80 Nov 9 15:30 test~
```

```text
./dir:
total 0
-rw-r–r– 1 theo theo 0 Nov 9 15:31 test
```

```text
∼/B-PSU-100> ./my_ls /bin
bash date kmod nano su uncompress
bunzip2 dd less netstat sync vdir
bzcat df lessecho networkctl systemctl wdctl
bzcmp dir lessfile nisdomainname systemd which
bzdiff dmesg lesskey pidof systemd-ask-password wslpath
bzegrep dnsdomainname lesspipe ping systemd-escape ypdomainname
bzexe domainname ln ping4 systemd-hwdb zcat
bzfgrep echo login ping6 systemd-inhibit zcmp
bzgrep egrep loginctl ps systemd-machine-id-setup zdiff
bzip2 false ls pwd systemd-notify zegrep
bzip2recover fgrep lsblk rbash systemd-sysusers zfgrep
bzless findmnt lsmod readlink systemd-tmpfiles zforce
bzmore fuser mkdir rm systemd-tty-ask-password-agent zgrep
cat grep mknod rmdir tar zless
chgrp gunzip mktemp rnano tcsh zmore
chmod gzexe more run-parts tempfile znew
chown gzip mount sed touch
cp hostname mountpoint sh true
cpio ip mt sleep udevadm
csh journalctl mt-gnu ss umount
dash kill mv stty uname
```

## FINAL MARK

### Mark: 18 / 19 (94.7%)

- basic tests (5 / 5)
- '-l' option tests (7 / 7)
- '-R' option test (1 / 1)
- combining option tests (3 / 3)
- '-t' option tests (2 / 2)
- char device tests (0 / 1)
