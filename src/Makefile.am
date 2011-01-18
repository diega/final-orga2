bin_PROGRAMS = filter mask restar
filter_SOURCES = filter.c

mask_SOURCES = mask.c
mask_CPPFLAGS = $(OPENCV_CFLAGS)
mask_LDADD = $(OPENCV_LIBS)

restar_SOURCES = testRestar.c restar.nasm
restar_CPPFLAGS = -m32
restar_LDFLAGS = -m32

.nasm.o:
	@NASM@ -felf -o $@ $<
