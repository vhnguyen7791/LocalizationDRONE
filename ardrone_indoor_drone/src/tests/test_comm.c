#include "test_comm.h"

#ifdef TEST_COMM

#define DEST_IP "192.168.1.3"

void test_comm_main()
{
   char message[COMM_MESSAGE_SIZE];
   char message_sent_id;

   printf("demo program launched\n\n");
   udp_listen_once(message, COMM_MESSAGE_SIZE, PORT_SERVER_TO_DRONE);
   while (1){
      if (message[0] == 'I'){
         printf("message init received\n");
         strcpy(message_sent_id, UDP_MESSAGE_DRONE_INIT_ID);
         udp_send(DEST_IP, message_sent_id, UDP_MESSAGE_DRONE_SIZE, PORT_DRONE_TO_SERVER);
         udp_listen_once(message, COMM_MESSAGE_SIZE, PORT_SERVER_TO_DRONE);
      }
      else if (message[0] == 'S'){
         printf("message sync received\n");
         strcpy(message_sent_id, UDP_MESSAGE_DRONE_SYNC_ID);
         udp_send(DEST_IP, message_sent_id, UDP_MESSAGE_DRONE_SIZE, PORT_DRONE_TO_SERVER);
         udp_listen_once(message, COMM_MESSAGE_SIZE, PORT_SERVER_TO_DRONE);

      }
      else if (message[0] == 'X'){
               printf("message quit received\n");
               break;
      }
   }
}

#endif
