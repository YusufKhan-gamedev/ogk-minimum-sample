/* Released under Public Domain */

#include <xf86drm.h>
#include "nvidia_drm.h"

#include <sys/mman.h>
#include <errno.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <fcntl.h>


int main() {
	struct drm_nvidia_get_dev_info_params input = {};
	int ret;
	int fd;

	fd = open("/dev/dri/card0", O_RDWR|O_CREAT);

	ret = drmIoctl(fd, DRM_IOCTL_NVIDIA_GET_DEV_INFO, &input);

	printf("fd: %i gpu_id: %i ret: %i\n", fd, input.gpu_id, ret);

	return 0;
}
