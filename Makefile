# our beloved g++ compiler
# goes into a variable!
GCC = g++ 

Checkpoint3: TestCheckpoint.o CartPoint.o CartVector.o GameObject.o CoralReef.o Cave.o Fish.o
	$(GCC) TestCheckpoint.o CartPoint.o CartVector.o GameObject.o CoralReef.o Cave.o Fish.o -o Checkpoint3 

TestCheckpoint.o: TestCheckpoint.cpp
	$(GCC) -c TestCheckpoint.cpp

CartPoint.o: CartPoint.cpp
	$(GCC) -c CartPoint.cpp

CartVector.o: CartVector.cpp
	$(GCC) -c CartVector.cpp

GameObject.o: GameObject.cpp
	$(GCC) -c GameObject.cpp

CoralReef.o: CoralReef.cpp
	$(GCC) -c CoralReef.cpp

Cave.o: Cave.cpp
	$(GCC) -c Cave.cpp

Fish.o: Fish.cpp
	$(GCC) -c Fish.cpp

clean:
	rm -Rf TestCheckpoint.o CartPoint.o CartVector.o GameObject.o CoralReef.o Cave.o Fish.o Checkpoint3 
