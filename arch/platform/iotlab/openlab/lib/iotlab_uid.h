#ifndef IOTLAB_UID_H_
#define IOTLAB_UID_H_

#include "unique_id.h"

// Extract a 16bit UUID uniq for all the platform
// Keeping uid8[9], (uid8[8] | (uid8[10] << 7)) % 256
//
//     The validity has been tested on all nodes UID that passed autotest

static inline uint16_t iotlab_uid() {
    // Endianness hasn't been respected though, MAY be updated one time
	return (uid->uid8[8] | (uid->uid8[10] << 7)) << 8 | uid->uid8[9];
}

#endif /* IOTLAB_UID_H_ */
