
# Copy Files project

Device info:
- CPU AMD Ryzen 7 4800H 8 cores
- RAM 19,7 GB
- SSD Intel SS DSC2KB038T8
- OS  Ubuntu 22.04.5 LTS


## C++

Compile:
```
g++ FileCopyUtility.cpp -o FileCopyUtility
```

Run:
```bash
./FileCopyUtility source_folder destination_folder
```
Copy 1 .iso file. Size 6,2 GB

- btrfs -> ext2     Total time taken: 14.2796 seconds.
- btrfs -> hfs      Total time taken: 10.4778 seconds.
- btrfs -> hgfs     Total time taken: 9.67954 seconds.
- btrfs -> jfs      Total time taken: 13.4499 seconds.
- btrfs -> xfs      Total time taken: 14.6561 seconds.
- btrfs -> ext4     Total time taken: 8.41756 seconds.

Copy 1M files. Size 102 MB

- ext4 -> btrfs     Total time taken: 388.853 seconds.
- ext4 -> ext2      Total time taken: 254.209 seconds.
- ext4 -> hfs       Total time taken: 387.579 seconds.
- ext4 -> hgfs      Total time taken: 206.736 seconds.
- ext4 -> jfs       Total time taken: 352.081 seconds.
- ext4 -> xfs       Total time taken: 219.9 seconds.

## Python

Run:
```bash
python FileCopyUtility.py source_folder destination_folder
```

## Java

Run:
```
java FileCopyUtility source_folder destination_folder
```