tests:
	$(MAKE) library
	g++ -Llib/ -lLargeNumber test/all_tests.cpp -o obj/test.o

library:
	g++ -c src/LargeNumber.cpp src/LargeNumber.h
	mv LargeNumber.o obj/
	ar rvs lib/libLargeNumber.a obj/LargeNumber.o

clean:
	rm -rf *.o
	rm -rf *.a