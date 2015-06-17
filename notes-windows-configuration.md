# 32-bit x86

* visual studio 2010
* qt4.x
* boost
* liblas

LIBLAS_ROOT ==> D:\Liblas (bin, include, lib)
BOOST_INCLUDEDIR ==> include
BOOST_LIBDIR ==> lib


You then need to set the following two environment variables to point respectively to the path of the libraries and the headers

  > BOOST_LIBRARYDIR=C:\dev\libboost_1_54_0\lib32-msvc-10.0
  > BOOST_INCLUDEDIR=C:\dev\libboost_1_54_0
  
You also need to add in your PATH environment variable, the path to the Boost dll's:

  > I add to my PATH environment variable C:\dev\libboost_1_54_0\lib32-msvc-10.0
  
With other versions of Tom installers, the path to libraries may end with lib32 instead of lib32-msvc-10.0.

   I selected C:\Qt\4.8.2 so QTDIR is set to C:\Qt\4.8.2

   I add C:\Qt\4.8.2\bin to my PATH


C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\bin

cvtres.exe ==> cvtres1.exe

PDB what for? For Debugging.
> http://stackoverflow.com/questions/12954821/cannot-find-or-open-the-pdb-file-in-visual-studio-c-2010/12954908#12954908
> `Tools->Options->Debugging->Symbols`
> and select checkbox "Microsoft Symbol Servers"

Load PDB or `F5` ==> `Control + F5`

link err, failure to convert to COFF
Incremental Linking: Yes ==> No
> http://fisnikhasani.com/error-lnk1123-failure-during-conversion-to-coff-file-invalid-or-corrupt/

# SVN

```shell
# 1
svn update
svn status
svn diff
svn commit -m 'commit message'
# 2
svn merge ?
svn revert ?
svn resolve ?
# 3
svn log
```

CMakeList.txt

VS Extensions

* VsVim
* tssts

