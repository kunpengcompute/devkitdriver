# SVF Patch README

## 1. Features
- Get sparse bit Vector of value and save into file.
- Wpa Parallel optimization base on LLVM ThreadPool.
- Output a new moudle after running wpa.

## 2. Language
C++ 14

## 3. Environment
OS: Linux

ThirdParty(recommend): LLVM-10.0


## 4. Build
### 4.1 build llvm10.0
```
Choose Tags llvmorg-10.0.0
git clone https://github.com/llvm/llvm-project.git
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DLLVM_ENABLE_PROJECTS="clang;clang++" ../llvm
```
### 4.2 Get SVF and patch for SVF
```
Choose Tags SVF-1.9 
git clone https://github.com/SVF-tools/SVF.git
cd SVF-1.9
mv SVF_Patch/SVF-1.9-parallelization-and-modified-output .
patch -p1 < SVF-1.9-parallelization-and-modified-output
```
### 4.3 Build SVF 1.9
```
sh build.sh
```
## 5. Run
```
cd SVF-1.9/Release-build/bin
./wpa -ander -print-aliases BC_File_path
```
We will get alias file and module file in Release-build/bin folder.
