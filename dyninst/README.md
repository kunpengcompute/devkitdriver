# Dyninst Patch README

## 1. Features
- .support two instructions
- .fix aarch64 support bug

## 2. Language
C++

## 3. Environment
OS: Linux

## 4. Build
### 4.1 build dyninst
```
Choose Tags dyninst-10.1.0
git clone https://github.com/dyninst/dyninst.git
cd dyninst
git checkout v10.1.0
```
### 4.2 patch for dyninst
```
patch -p1 -l < dyninst_fix_patch.patch
```
### 4.3 Build dyninst
```
cmake .
```