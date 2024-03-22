FROM --platform=linux/amd64 alpine:edge

ENV TZ=Europe/Moscow

ENV LANG C.UTF-8
ENV LC_ALL C.UTF-8


RUN apk update && apk upgrade
RUN apk add --no-cache git openssh build-base clang make cmake lld compiler-rt zsh
ENV CC=/usr/bin/clang
ENV CXX=/usr/bin/clang++
