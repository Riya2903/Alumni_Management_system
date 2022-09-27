OBJS = menus.o alumni_class.cpp admin_class.cpp student_class.cpp  
o = -lpthread
HEAD = alumni_class.hpp
HH = student_class.hpp
HT = admin_class.hpp
CO = g++ -g -Wall -o
CC = g++ -c
RM = rm *.o 

test:  $(OBJS) $(HEAD) $(HH) $(HT)
	$(CO) test $(OBJS) $(o)

menus.o: menus.cpp
	$(CC) menus.cpp $(o) 
#alumni_class.o: alumni_class.cpp
#	$(CO) alumni_class.cpp $(o)

#student_class.o: student_class.cpp
#	$(CO) student_class.cpp $(o)
#admin_class.o: admin_class.cpp
#	$(CO) admin_class.cpp $(o)
#student_class.o: $(ST) $(HH)
#	$(CC) $(ST) -fPIC

#alumni_class.o: $(AL) $(HEAD)
#	$(CC) $(AL) -fPIC

#admin_class.o: $(AD) $(HT)
#	$(CC) $(AD) -fPIC

#validation.o: $(V)
#	$(CC) $(V) -fPIC

#student_files.o: $(SF) 
#	$(CC) $(SF) -fPIC

#alumni_files.o: $(AF)
#	$(CC) $(AF) -fPIC


clean:
	$(RM)



