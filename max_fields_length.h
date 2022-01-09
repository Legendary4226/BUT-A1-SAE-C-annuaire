#define FILE_MAX_NAME_LENGTH 26
#define FILE_MAX_CITY_LENGTH 24
#define FILE_MAX_CODEPOSTAL_LENGTH 6
#define FILE_MAX_EMAIL_LENGTH 48
#define FILE_MAX_PROFESSION_LENGTH 20
#define FILE_MAX_PHONE_LENGTH 15

#define FILE_MAX_LINE_LENGTH ( \
        2 * FILE_MAX_NAME_LENGTH \
        + FILE_MAX_CITY_LENGTH                        \
        + FILE_MAX_CODEPOSTAL_LENGTH                  \
        + FILE_MAX_PHONE_LENGTH                       \
        + FILE_MAX_EMAIL_LENGTH                       \
        + FILE_MAX_PROFESSION_LENGTH                  \
    )

#define MAX_USER_INPUT_LENGTH (2 * FILE_MAX_LINE_LENGTH)
