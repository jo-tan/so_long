FROM	alpine

# add packages for dev
RUN	apk update && \
	apk upgrade && \
	apk add --no-cache build-base git vim valgrind

# git minilibX and others from 42paris github
RUN git clone https://github.com/42paris/minilibx-linux mlx && \
	apk add libxext-dev && \
	apk add libbsd-dev && \
    apk add libx11-dev

# install and move minilibx header files to specific location   
RUN	cd mlx; ./configure && \
    cp libmlx.a /usr/local/lib/ && \
    mkdir /usr/local/include && \
    cp mlx.h /usr/local/include/mlx.h && \
    cp mlx_int.h /usr/local/include/mlx_int.h

