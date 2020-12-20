import os

# export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/serendipita/Documents/uppaalLibrary/build/
# g++ main.cpp -o main build/libconfig.so  #  works after export
# g++ -I. -L.  main.cpp  -o main -lconfig # works after export, is very important add -I. -L.
# g++ -I. -L./build/ main.cpp -o main -lconfig  # whe lib is in build
# ./main
#  g++ -I. -I./lib/jsoncpp/include/ -L./build/ -L./build/lib/ main.cpp -o main -lconfig -ljsoncpp

# Check uppaal version: last

# ./lib/uppaal/bin-Linux/verifyta foo.xml foo.q  #without --learning-method 5)
# ./lib/uppaal/uppaal foo.xml

# uppaaltest foo.xml foo.q

# uppaal setup or libconfig generation ? -> test with lfconfig file of other project

def callUppaal(f):
  print("calling Uppaal .. ")
  #command_line = "../lib/uppaal/bin-Linux/verifyta " + f[0] + " " + f[1] + " --learning-method 5"
  command_line = "/home/serendipita/Documents/uppaalLibrary/lib/uppaal/bin-Linux/verifyta " + f[0] + " " + f[1] + " --learning-method 5"
  #print(line)
  n = os.popen(command_line).readlines()
  print(n)


f = ["/home/serendipita/Documents/uppaalLibrary/test/foo.xml", "/home/serendipita/Documents/uppaalLibrary/test/foo.q"]
callUppaal(f)
#print(callUppaal(f))

