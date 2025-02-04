CC = cosmocc
CXX = cosmoc++
AR = cosmoar
ZIPOBJ = zipobj
CFLAGS = -I./lib/sdl2 -I./includes -lm -fopenmp -O3
CXXFLAGS = $(CFLAGS)
SDL2_LIB = build/libSDL2.a
SDL2_LIB_OBJS = build/lib/sdl2/SDL_dynapi_cosmo.o
SDL2_BUNDLED_RELEASE = 2.28.5
MAIN_EXAMPLE = build/pgfx
MAIN_EXAMPLE_OBJS = build/raytracer.o

.PHONY: default build_setup clean

default: | build_setup
	$(MAKE) $(MAIN_EXAMPLE)

build_setup:
	mkdir -p build
	cp -rf ./lib/compiled/* ./build

$(SDL2_LIB): $(SDL2_LIB_OBJS)
	$(AR) r $@ $^

$(MAIN_EXAMPLE): $(MAIN_EXAMPLE_OBJS) $(SDL2_LIB)
	$(CC) $(LDLIBS) -o $@ $^

build/lib/sdl2/%.o: lib/sdl2/%.c
	$(CC) -c $(CFLAGS) -o $@ $^

build/%.o: src/%.c
	$(CC) -c $(CFLAGS) -o $@ $^

build/%.o: src/%.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $^

clean:
	rm -rf build