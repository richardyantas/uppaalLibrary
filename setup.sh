# git submodule add https://github.com/open-source-parsers/jsoncpp lib/jsoncpp
# git remote add origin https://github.com/richardyantas/uppaalLibrary
# git remote remove origin
# git remote add origin https://github.com/richardyantas/uppaalLibrary.gitg

# ➜  bin git:(main) ./test_config 
# 5
# ➜  bin git:(main) echo $LD_LIBRARY_PATH

# ➜  bin git:(main)

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/serendipita/Documents/uppaalLibrary/build/lib/

/lib/uppaal/bin-Linux/verifyta test/foo.xml test/foo.q