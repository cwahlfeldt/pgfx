CC = cosmocc
CXX = cosmoc++
AR = cosmoar

CFLAGS = -I./lib/sdl2 -I./lib/gl3w -I./includes
CXXFLAGS = $(CFLAGS)

SDL2_LIB = build/libSDL2.a
# Add all SDL2 object files needed
SDL2_LIB_OBJS = \
    build/lib/sdl2/SDL_dynapi_cosmo.o \
    # Add other SDL2 objects if needed

GL3W_LIB_OBJS = build/lib/gl3w/gl3w.o
RENDERER_LIB_OBJS = build/renderer.o

MAIN_EXAMPLE = build/pgfx
MAIN_EXAMPLE_OBJS = build/main.o

# Add required libraries for linking
LDFLAGS = -ldl
LDLIBS = $(SDL2_LIB) $(LDFLAGS)

.PHONY: default build_setup clean

default: | build_setup
	$(MAKE) $(MAIN_EXAMPLE)

build_setup:
	mkdir -p build
	mkdir -p build/lib/sdl2
	mkdir -p build/lib/gl3w
	cp -rf ./lib/compiled/* ./build

# Build SDL2 library
$(SDL2_LIB): $(SDL2_LIB_OBJS)
	$(AR) r $@ $^

# Link the main executable
$(MAIN_EXAMPLE): $(MAIN_EXAMPLE_OBJS) $(SDL2_LIB) $(GL3W_LIB_OBJS) $(RENDERER_LIB_OBJS)
	$(CC) -o $@ $^ $(LDLIBS)

# Compilation rules
build/lib/sdl2/%.o: lib/sdl2/%.c
	$(CC) -c $(CFLAGS) -o $@ $^

build/lib/gl3w/%.o: lib/gl3w/%.c
	$(CC) -c $(CFLAGS) -o $@ $^

build/%.o: src/%.c
	$(CC) -c $(CFLAGS) -o $@ $^

build/%.o: src/%.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $^

clean:
	rm -rf build