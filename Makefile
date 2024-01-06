CXXFLAGS+=--std=c++20 -Wall -Wextra -O0 -g -D_GLIBCXX_DEBUG
CXXFLAGS+=-fdiagnostics-color=auto
LDFLAGS+=-lutil -lboost_iostreams -lboost_system -lboost_filesystem

%.o: %.cc gnuplot-iostream.h
	@echo Compiling $@
	$(CXX) $(CXXFLAGS) -c $< -o $@

loan_interest: loan_interest.o
	@echo Linking $@
	$(CXX) -o $@ $^ $(LDFLAGS)
	@printf "\nmake all finished\n\n"

clean:
	rm -f *.o
	rm -rf unittest-errors unittest-output
	rm -f $(ALL_EXAMPLES) $(TEST_BINARIES)
	# Windows compilation
	rm -f *.exe *.obj
	# files created by demo scripts
	rm -f my_graph_*.png external_binary.dat external_binary.gnu external_text.dat external_text.gnu inline_binary.gnu inline_text.gnu
	@printf "\nmake clean finished\n\n"
