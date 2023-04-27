#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_TEST_CASES 10

// RLC PDU Header Structure
struct rlc_pdu_header {
    unsigned char dc:1;
    unsigned char rf:1;
    unsigned char p:1;
    unsigned char fi:2;
    unsigned char e:1;
    unsigned char sn:4;
};

// Function to generate test data from user input
void generate_test_data(char test_cases[MAX_TEST_CASES][MAX_BUFFER_SIZE]) {
    int i = 0;
    printf("Enter test cases (press enter to stop):\n");
    while (i < MAX_TEST_CASES) {
        fgets(test_cases[i], MAX_BUFFER_SIZE, stdin);
        if (test_cases[i][0] == '\n') {
            break;
        }
        i++;
    }
}

// Function to decode RLC PDU and display the content
void decode_pdu(char *buffer) {
    struct rlc_pdu_header pdu_header;
    memcpy(&pdu_header, buffer, sizeof(struct rlc_pdu_header));
    printf("D/C:%d ", pdu_header.dc);
    printf("RF:%d ", pdu_header.rf);
    printf("P:%d ", pdu_header.p);
    printf("FI:%02x ", pdu_header.fi);
    printf("\n");

    if (pdu_header.fi == 0x01) {
        printf("First byte of the Data field corresponds to the first byte of a RLC SDU\n");
    } else if (pdu_header.fi == 0x02) {
        printf("Last byte of the Data field corresponds to the last byte of a RLC SDU\n");
    } else if (pdu_header.fi == 0x03) {
        printf("First and last byte of the Data field correspond to the first and last byte of a RLC SDU\n");
    }

    printf("E:%d ", pdu_header.e);
    printf("Sequence Number: %d\n", pdu_header.sn);
    printf("<<<<<<<<<<<< DECODE SUCCESSFUL !! >>>>>>>>>>>>\n");
}

int main() {
    char test_cases[MAX_TEST_CASES][MAX_BUFFER_SIZE];
    int i, j;
    generate_test_data(test_cases);

    for (i = 0; i < MAX_TEST_CASES && test_cases[i][0] != '\0'; i++) {
        char *buffer = test_cases[i];
        int length = strlen(buffer);
        if (buffer[length - 1] == '\n') {
            buffer[length - 1] = '\0'; // Remove newline character
        }
        printf("Input: %s\n", buffer);
        decode_pdu(buffer);
        printf("Press Enter to decode next PDU from input:");
        getchar();
    }

    return 0;
}
