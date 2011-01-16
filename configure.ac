AC_INIT([final-orga2], [0.1], [dclopez@dc.uba.ar])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([foreign -Wall -Werror])
AC_CANONICAL_HOST
AC_PROG_CC_C99
AM_PROG_CC_C_O
AC_PROG_NASM
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile src/Makefile])
PKG_CHECK_MODULES(OPENCV, \
  opencv
  )
AC_OUTPUT
