#ifndef OS_BIOMETRY_API_H
#define OS_BIOMETRY_API_H

#include <stdint.h>
#include <stddef.h>

typedef enum {
    OS_API_SUCCESS = 0,
    OS_API_ERR_NOT_FOUND = -1,
    OS_API_ERR_INVALID_DATA = -2,
    OS_API_ERR_ACCESS_DENIED = -3
} os_api_status_t;

typedef struct {
    char id[64];
} os_user_id_t;


os_api_status_t os_bio_identify_fingerprint(const uint8_t* image_data, size_t size, os_user_id_t* out_user);

os_api_status_t os_bio_identify_face(const uint8_t* image_data, size_t size, os_user_id_t* out_user);

os_api_status_t os_bio_identify_iris(const uint8_t* image_data, size_t size, os_user_id_t* out_user);

typedef enum {
    VOICE_AUTH_FIXED = 0,
    VOICE_AUTH_PROMPTED = 1,
    VOICE_AUTH_DIALOGUE = 2
} os_voice_auth_mode_t;

os_api_status_t os_bio_identify_voice(const uint8_t* audio_data, size_t size, os_voice_auth_mode_t mode, os_user_id_t* out_user);

os_api_status_t os_bio_identify_dna(const uint8_t* dna_sequence, size_t seq_len, os_user_id_t* out_user);


os_api_status_t os_voice_recognize_text(const uint8_t* audio, size_t size, char* out_text_buffer, size_t max_len);
os_api_status_t os_voice_synthesize_en(const char* text, uint8_t** out_audio, size_t* out_size);
os_api_status_t os_voice_synthesize_multi(const char* text, const char* lang_code, uint8_t** out_audio, size_t* out_size);


os_api_status_t os_text_semantic_vectorize(const char* text, float* out_vector_array, size_t* array_size);
os_api_status_t os_emotion_recognize_voice(const uint8_t* audio, size_t size, char* out_emotion, size_t max_len);
os_api_status_t os_emotion_recognize_handwriting(const uint8_t* image, size_t size, char* out_emotion, size_t max_len);

#endif // OS_BIOMETRY_API_H