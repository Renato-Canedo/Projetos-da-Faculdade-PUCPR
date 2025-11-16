#include <security/pam_modules.h>
#include <security/pam_ext.h>
#include <syslog.h>
#include <string.h>
#include <stdlib.h>

static int is_palindrome(const char s) {
    int i = 0;
    int j = (int)strlen(s) - 1;
    while (i < j) {
        if (s[i] != s[j]) return 0;
        i++; j--;
    }
    return 1;
}

PAM_EXTERN int pam_sm_authenticate(pam_handle_tpamh, int flags, int argc, const char argv) {
    int retval;
    const char username = NULL;
    const charpassword = NULL;

    retval = pam_get_user(pamh, &username, NULL);
    if (retval != PAM_SUCCESS) {
        pam_syslog(pamh, LOG_NOTICE, "Não consegui recuperar o usuário!");
        return PAM_AUTH_ERR;
    }

    retval = pam_get_authtok(pamh, PAM_AUTHTOK, &password, NULL);
    if (retval != PAM_SUCCESS || password == NULL) {
        pam_syslog(pamh, LOG_NOTICE, "Não consegui recuperar a senha do usuário %s!", username ? username : "??");
        return PAM_AUTH_ERR;
    }

    if (is_palindrome(password)) {
        pam_syslog(pamh, LOG_NOTICE, "A senha do usuário %s é um palíndromo!", username);
    } else {
        pam_syslog(pamh, LOG_NOTICE, "A senha do usuário %s NÃO é um palíndromo.", username);
    }

    return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_setcred(pam_handle_t *pamh, int flags, int argc, const char argv) {
    return PAM_SUCCESS;
}