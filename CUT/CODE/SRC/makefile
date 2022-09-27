OBJS = menus.o
o = -lpthread
HEAD = alumni_class.hpp
HH = student_class.hpp
HT = admin_class.hpp
CO = g++ -o
CC = g++ -c
RM = rm *.o *.so

test:  $(OBJS) $(HEAD) $(HH) $(HT)
	$(CO) test $(OBJS) $(o)

menus.o: menus.cpp
	$(CC) menus.cpp $(O) 

#liblibrary.so: student_class.o alumni_class.o admin_class.o
#	$(CO) -shared -WL, --whole-archive -lAlgatorc -Wl, --no-whole-archive
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



