ifeq ($(shell uname),Darwin)
	EXT := dylib
else
	EXT := so
endif

all: target/debug/libmath.$(EXT)
	g++ src/main.cpp -L ./target/debug/ -lexample -o run
	LD_LIBRARY_PATH=./target/debug/ ./run

target/debug/libmath.$(EXT): src/lib.rs Cargo.toml
	cargo build

clean:
	rm -rf target
	rm -rf run
