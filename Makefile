CC = cosmocc
CXX = cosmoc++
AR = cosmoar

CFLAGS = -I./lib/sdl2 -I./lib/gl3w -I./includes -g
CXXFLAGS = $(CFLAGS)

SDL2_LIB = build/libSDL2.a
SDL2_LIB_OBJS = \
    build/lib/sdl2/SDL_dynapi_cosmo.o

GL3W_LIB_OBJS = build/lib/gl3w/gl3w.o

RENDERER_LIB_OBJS = \
    build/renderer/core/renderer.o \
    build/renderer/core/render_state.o \
    build/renderer/shaders/shader.o \
    build/renderer/shaders/shader_library.o \
    build/renderer/objects/primitives.o \
    build/renderer/objects/primitive_cache.o \
    build/renderer/lighting/light.o \
    build/renderer/math/vector.o \
    build/renderer/math/matrix.o

# Executables
MAIN_APP = build/pgfx
MAIN_APP_OBJS = build/main.o

# Examples
EXAMPLES_DIR = examples
EXAMPLES = \
    build/examples/cube_on_plane

# Add required libraries for linking
LDFLAGS = -ldl
LDLIBS = $(SDL2_LIB) $(LDFLAGS)

.PHONY: default build_setup clean examples

default: | build_setup
	$(MAKE) $(MAIN_APP)
	$(MAKE) examples

examples: $(EXAMPLES)

build_setup:
	mkdir -p build
	mkdir -p build/lib/sdl2
	mkdir -p build/lib/gl3w
	mkdir -p build/examples
	mkdir -p build/renderer/core
	mkdir -p build/renderer/shaders
	mkdir -p build/renderer/objects
	mkdir -p build/renderer/lighting
	mkdir -p build/renderer/math
	cp -rf ./lib/compiled/* ./build

# Build SDL2 library
$(SDL2_LIB): $(SDL2_LIB_OBJS)
	$(AR) r $@ $^

# Link executables
$(MAIN_APP): $(MAIN_APP_OBJS) $(SDL2_LIB) $(GL3W_LIB_OBJS) $(RENDERER_LIB_OBJS)
	$(CC) -o $@ $^ $(LDLIBS)

# Link examples
build/examples/%: build/examples/%.o $(SDL2_LIB) $(GL3W_LIB_OBJS) $(RENDERER_LIB_OBJS)
	$(CC) -o $@ $^ $(LDLIBS)

# Compilation rules
build/lib/sdl2/%.o: lib/sdl2/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $^

build/lib/gl3w/%.o: lib/gl3w/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $^

build/renderer/%.o: src/renderer/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $^

build/examples/%.o: examples/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $^

build/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $^

build/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) -o $@ $^

clean:
	rm -rf build