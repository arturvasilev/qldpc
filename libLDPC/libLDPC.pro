#-------------------------------------------------
#
# Project created by QtCreator 2017-09-28T03:41:54
#
#-------------------------------------------------

QT       += core gui\
		widgets\

TARGET = libLDPC
TEMPLATE = lib
CONFIG += staticlib

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        libldpc.cpp\
        ../LDPC-4Qt/ldpc4qt.cpp \
    ../LDPC-4Qt/ldpccode.cpp \
    ../LDPC-4Qt/ldpcdecode.cpp \
    ../LDPC-4Qt/ldpcencode.cpp \
    ../LDPC-4Qt/ldpcmakegen.cpp \
    ../LDPC-4Qt/ldpcmakeldpc.cpp \
    ../LDPC-4Qt/ldpcqconversions.cpp \
    ../LDPC-4Qt/ldpctransmitsimulation.cpp \
    ../LDPC-4Qt/ldpcverify.cpp \
    ../LDPC-4Qt/test.cpp \
    ../LDPC-codes/alist-to-pchk.c \
    ../LDPC-codes/alloc.c \
    ../LDPC-codes/blockio.c \
    ../LDPC-codes/channel.c \
    ../LDPC-codes/check.c \
    ../LDPC-codes/dec.c \
    ../LDPC-codes/decode.c \
    ../LDPC-codes/distrib.c \
    ../LDPC-codes/enc.c \
    ../LDPC-codes/encode.c \
    ../LDPC-codes/extract.c \
    ../LDPC-codes/intio.c \
    ../LDPC-codes/make-gen.c \
    ../LDPC-codes/make-ldpc.c \
    ../LDPC-codes/make-pchk.c \
    ../LDPC-codes/mod2convert-test.c \
    ../LDPC-codes/mod2convert.c \
    ../LDPC-codes/mod2dense-test.c \
    ../LDPC-codes/mod2dense.c \
    ../LDPC-codes/mod2sparse-test.c \
    ../LDPC-codes/mod2sparse.c \
    ../LDPC-codes/open.c \
    ../LDPC-codes/pchk-to-alist.c \
    ../LDPC-codes/print-gen.c \
    ../LDPC-codes/print-pchk.c \
    ../LDPC-codes/rand-src.c \
    ../LDPC-codes/rand-test.c \
    ../LDPC-codes/rand.c \
    ../LDPC-codes/rcode.c \
    ../LDPC-codes/transmit.c \
    ../LDPC-codes/verify.c

HEADERS += \
        libldpc.h\
        ../LDPC-4Qt/ldpc4qt.h \
    ../LDPC-4Qt/ldpcchannel.h \
    ../LDPC-4Qt/ldpccode.h \
    ../LDPC-4Qt/ldpcdecode.h \
    ../LDPC-4Qt/ldpcdecodingmethod.h \
    ../LDPC-4Qt/ldpcencode.h \
    ../LDPC-4Qt/ldpcmakegen.h \
    ../LDPC-4Qt/ldpcmakeldpc.h \
    ../LDPC-4Qt/ldpcqconversions.h \
    ../LDPC-4Qt/ldpctransmitsimulation.h \
    ../LDPC-4Qt/ldpcverify.h \
    ../LDPC-4Qt/rcodevars.h \
    ../LDPC-codes/alloc.h \
    ../LDPC-codes/blockio.h \
    ../LDPC-codes/channel.h \
    ../LDPC-codes/check.h \
    ../LDPC-codes/dec.h \
    ../LDPC-codes/distrib.h \
    ../LDPC-codes/enc.h \
    ../LDPC-codes/intio.h \
    ../LDPC-codes/mod2convert.h \
    ../LDPC-codes/mod2dense.h \
    ../LDPC-codes/mod2sparse.h \
    ../LDPC-codes/open.h \
    ../LDPC-codes/rand.h \
    ../LDPC-codes/rcode.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    ../LDPC-4Qt/LICENSE \
    ../LDPC-4Qt/README.md \
    ../LDPC-codes/randfile \
    ../LDPC-codes/run-examples \
    ../LDPC-codes/sparse-encode.pdf \
    ../LDPC-codes/ex-dep \
    ../LDPC-codes/ex-ham7a \
    ../LDPC-codes/ex-ham7b \
    ../LDPC-codes/ex-ldpc-encode \
    ../LDPC-codes/ex-ldpc36-1000a \
    ../LDPC-codes/ex-ldpc36-5000a \
    ../LDPC-codes/ex-ldpcvar-5000a \
    ../LDPC-codes/ex-wrong-model \
    ../LDPC-codes/LDPC-install \
    ../LDPC-codes/channel.html \
    ../LDPC-codes/decode-detail.html \
    ../LDPC-codes/decoding.html \
    ../LDPC-codes/dep-H.html \
    ../LDPC-codes/encoding.html \
    ../LDPC-codes/examples.html \
    ../LDPC-codes/github.html \
    ../LDPC-codes/index.html \
    ../LDPC-codes/install.html \
    ../LDPC-codes/mod2convert.html \
    ../LDPC-codes/mod2dense.html \
    ../LDPC-codes/mod2sparse.html \
    ../LDPC-codes/modify.html \
    ../LDPC-codes/modules.html \
    ../LDPC-codes/pchk.html \
    ../LDPC-codes/progs.html \
    ../LDPC-codes/rand.html \
    ../LDPC-codes/refs.html \
    ../LDPC-codes/release.html \
    ../LDPC-codes/sparse-LU.html \
    ../LDPC-codes/support.html \
    ../LDPC-codes/COPYRIGHT \
    ../LDPC-codes/ex-dep-out \
    ../LDPC-codes/ex-ham7a-out \
    ../LDPC-codes/ex-ham7b-out \
    ../LDPC-codes/ex-ldpc-encode-out \
    ../LDPC-codes/ex-ldpc36-1000a-out \
    ../LDPC-codes/ex-ldpc36-5000a-out \
    ../LDPC-codes/ex-ldpcvar-5000a-out \
    ../LDPC-codes/ex-wrong-model-out \
    ../LDPC-codes/LGPL \
    ../LDPC-codes/License.txt \
    ../LDPC-codes/mod2convert-test-out \
    ../LDPC-codes/mod2dense-test-out \
    ../LDPC-codes/mod2sparse-test-out \
    ../LDPC-codes/README.md
