/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-05-20     bigmagic     first version
 */

#include <rtthread.h>
#include "am_cpu_test.h"
#include "dhmk.h"
#include "coremark.h"
#include "benchmark.h"
// #define THREAD_PRIORITY 3
// #define THREAD_STACK_SIZE 512
// #define THREAD_TIMESLICE 5

// static rt_thread_t tid1 = RT_NULL;
// static rt_thread_t tid2 = RT_NULL;
// static char out_buf[16];
// extern char *itoa(unsigned int val, char *str, int base);

// static void low_prior_entry(void *parameter)
// {
//     rt_uint32_t count = 0, id;
//     while (1)
//     {
//         id = (rt_uint32_t)parameter;
//         // itoa(count++, out_buf, 10);
//         if (count >= 7)
//             break;
//         rt_kprintf("thread%u count: %u\n", id, count++);
//         rt_thread_mdelay(40);
//     }
//     rt_kprintf("thread%u exit\n", id);
// }

// ALIGN(RT_ALIGN_SIZE)
// static char thread3_stack[1024];
// static struct rt_thread thread3;
// static void high_prior_entry(void *param)
// {
//     rt_uint32_t count = 0;
//     for (count = 0; count < 4; ++count)
//     {
//         rt_kprintf("thread3 count: %d\n", count);
//     }
//     rt_kprintf("thread3 exit\n");
// }

// int thread_sample(void)
// {
//     tid1 = rt_thread_create("thread1",
//                             low_prior_entry, (void *)1,
//                             THREAD_STACK_SIZE,
//                             THREAD_PRIORITY, THREAD_TIMESLICE);

//     if (tid1 != RT_NULL)
//     {
//         rt_thread_startup(tid1);
//     }

//     tid2 = rt_thread_create("thread2",
//                             low_prior_entry, (void *)2,
//                             THREAD_STACK_SIZE,
//                             THREAD_PRIORITY, THREAD_TIMESLICE);

//     if (tid2 != RT_NULL)
//     {
//         rt_thread_startup(tid2);
//     }

//     // rt_thread_init(&thread3,
//     //                "thread3",
//     //                high_prior_entry,
//     //                RT_NULL,
//     //                &thread3_stack[0],
//     //                sizeof(thread3_stack),
//     //                THREAD_PRIORITY - 1, THREAD_TIMESLICE);
//     // rt_thread_startup(&thread3);

//     return 0;
// }

void logo_ieda(void)
{
    rt_kprintf("        :7YGB####BGPJ~.            :^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^.         :^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^::..                                            .^^^^^^^^^^^^^^^^^.                    \n");
    rt_kprintf("       7&@@@@@@@@@@@@@P^.          B@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@7..       Y@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&##BG5J7~:                                     5@@@@@@@@@@@@@@@@@J..                  \n");
    rt_kprintf("      ^@@@@@@@@@@@@@@@@5:.        .B@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@?:.       5@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&B57:                                !@@@@@@@@@@@@@@@@@@&!.                  \n");
    rt_kprintf("      ~@@@@@@@@@@@@@@@@G^.        .B@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&7:.       5@@@@@@@@@@@@@@@@@@@P555555PGB&@@@@@@@@@@@@@@@&G7:                            .#@@@@@@@@@@@@@@@@@@@G^.                 \n");
    rt_kprintf("      .5@@@@@@@@@@@@@@&7:.        .B@@@@@@@@@@@@@@@@@@&7!~~~~~~~~~~~~~~~~~~~~~~:.        5@@@@@@@@@@@@@@@@@@@7:.......:^7P&@@@@@@@@@@@@@@@#Y^                          Y@@@@@@@@@@@@@@@@@@@@@?:.                \n");
    rt_kprintf("       .!PB&@@@@@@&#BY!:.         .B@@@@@@@@@@@@@@@@@@#~:                                5@@@@@@@@@@@@@@@@@@@7:.          ~G@@@@@@@@@@@@@@@@#?.                       ~@@@@@@@@@@@@@@@@@@@@@@#^.                \n");
    rt_kprintf("          .^~!!7!!~^:..           .B@@@@@@@@@@@@@@@@@@#~:                                5@@@@@@@@@@@@@@@@@@@7:.           .P@@@@@@@@@@@@@@@@@P^.                    .B@@@@@@@@@@@@@@@@@@@@@@@Y:.               \n");
    rt_kprintf("                                  .B@@@@@@@@@@@@@@@@@@#~:.                               5@@@@@@@@@@@@@@@@@@@7:.            :#@@@@@@@@@@@@@@@@@B^.                   J@@@@@@@@@@@@@@@@@@@@@@@@&!.               \n");
    rt_kprintf("       ......:::^^~~!7?J:         .B@@@@@@@@@@@@@@@@@@#~:.                               5@@@@@@@@@@@@@@@@@@@7:.             J@@@@@@@@@@@@@@@@@@G^.                 ^@@@@@@@#@@@@@@@@@@@@@@@@@@G^.              \n");
    rt_kprintf("     .G######&&&@@@@@@@@7:.       .B@@@@@@@@@@@@@@@@@@#~:.                               5@@@@@@@@@@@@@@@@@@@7:.             ^&@@@@@@@@@@@@@@@@@@5:.                G@@@@@@G?@@@@@@@@@@@@@@@@@@@?:.             \n");
    rt_kprintf("     :&@@@@@@@@@@@@@@@@@?:.       .B@@@@@@@@@@@@@@@@@@#~:.                               5@@@@@@@@@@@@@@@@@@@7:.             .G@@@@@@@@@@@@@@@@@@@!:.              ?@@@@@@&7:5@@@@@@@@@@@@@@@@@@#~.             \n");
    rt_kprintf("     :&@@@@@@@@@@@@@@@@@7:.       .B@@@@@@@@@@@@@@@@@@#~:.                               5@@@@@@@@@@@@@@@@@@@7:.              Y@@@@@@@@@@@@@@@@@@@P:.             :&@@@@@@Y^.:#@@@@@@@@@@@@@@@@@@Y:.            \n");
    rt_kprintf("     :&@@@@@@@@@@@@@@@@@7:.       .B@@@@@@@@@@@@@@@@@@#~.                                5@@@@@@@@@@@@@@@@@@@7:.              ?@@@@@@@@@@@@@@@@@@@&~:             P@@@@@@B~:. ?@@@@@@@@@@@@@@@@@@&!.            \n");
    rt_kprintf("     :&@@@@@@@@@@@@@@@@@7:.       .B@@@@@@@@@@@@@@@@@@&5YJJJJJJJJJJJJJJJJJJ^             5@@@@@@@@@@@@@@@@@@@7:.              !@@@@@@@@@@@@@@@@@@@@?:.           7@@@@@@@?^.  .B@@@@@@@@@@@@@@@@@@G^.           \n");
    rt_kprintf("     :&@@@@@@@@@@@@@@@@@7:.       .B@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J:.           5@@@@@@@@@@@@@@@@@@@7:.              ~@@@@@@@@@@@@@@@@@@@@Y:.          :#@@@@@@P^:    !@@@@@@@@@@@@@@@@@@@?:.          \n");
    rt_kprintf("     :&@@@@@@@@@@@@@@@@@7:.       .B@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J:.           5@@@@@@@@@@@@@@@@@@@7:.              ~@@@@@@@@@@@@@@@@@@@@5^.          5@@@@@@#!:.     P@@@@@@@@@@@@@@@@@@#~.          \n");
    rt_kprintf("     :&@@@@@@@@@@@@@@@@@7:.       .B@@@@@@@@@@@@@@@@@@@BBBGGGGGGGGGGGGGGGGB?:.           5@@@@@@@@@@@@@@@@@@@7:.              ~@@@@@@@@@@@@@@@@@@@@P^.         !@@@@@@@J^.      ^&@@@@@@@@@@@@@@@@@@Y:.         \n");
    rt_kprintf("     :&@@@@@@@@@@@@@@@@@7:.       .B@@@@@@@@@@@@@@@@@@#!^:...................            5@@@@@@@@@@@@@@@@@@@7:.              ~@@@@@@@@@@@@@@@@@@@@5^.        .B@@@@@@G~:.       Y@@@@@@@@@@@@@@@@@@&!.         \n");
    rt_kprintf("     :&@@@@@@@@@@@@@@@@@7:.       .B@@@@@@@@@@@@@@@@@@#~:                                5@@@@@@@@@@@@@@@@@@@7:.              ~@@@@@@@@@@@@@@@@@@@@Y^.        Y@@@@@@&7:.        :#@@@@@@@@@@@@@@@@@@G^.        \n");
    rt_kprintf("     :&@@@@@@@@@@@@@@@@@7:.       .B@@@@@@@@@@@@@@@@@@#~:                                5@@@@@@@@@@@@@@@@@@@7:.              !@@@@@@@@@@@@@@@@@@@@?:.       ~@@@@@@@5^.          ?@@@@@@@@@@@@@@@@@@@?:.       \n");
    rt_kprintf("     :&@@@@@@@@@@@@@@@@@7:.       .B@@@@@@@@@@@@@@@@@@#~:.                               5@@@@@@@@@@@@@@@@@@@7:.              7@@@@@@@@@@@@@@@@@@@&!:.      .G@@@@@@B~:.          .B@@@@@@@@@@@@@@@@@@#~.       \n");
    rt_kprintf("     :&@@@@@@@@@@@@@@@@@7:.       .B@@@@@@@@@@@@@@@@@@#~:.                               5@@@@@@@@@@@@@@@@@@@7:.              Y@@@@@@@@@@@@@@@@@@@G^:       ?@@@@@@@?:.            ~@@@@@@@@@@@@@@@@@@@Y:.      \n");
    rt_kprintf("     :&@@@@@@@@@@@@@@@@@7:.       .B@@@@@@@@@@@@@@@@@@#~:.                               5@@@@@@@@@@@@@@@@@@@7:.              G@@@@@@@@@@@@@@@@@@@?^.      ^&@@@@@@&GPPPPPPPPPPPPPPP&@@@@@@@@@@@@@@@@@@&!.      \n");
    rt_kprintf("     :&@@@@@@@@@@@@@@@@@7:.       .B@@@@@@@@@@@@@@@@@@#~:.                               5@@@@@@@@@@@@@@@@@@@7:.             :&@@@@@@@@@@@@@@@@@@P^:       P@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@G^.     \n");
    rt_kprintf("     :&@@@@@@@@@@@@@@@@@7:.       .B@@@@@@@@@@@@@@@@@@#~:.                               5@@@@@@@@@@@@@@@@@@@7:.             ?@@@@@@@@@@@@@@@@@@#!:.      7@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@?:.    \n");
    rt_kprintf("     :&@@@@@@@@@@@@@@@@@7:.       .B@@@@@@@@@@@@@@@@@@#~:.                               5@@@@@@@@@@@@@@@@@@@7:.            .B@@@@@@@@@@@@@@@@@#7:.      :#@@@@@@#P5555555555555555555#@@@@@@@@@@@@@@@@@@#~.    \n");
    rt_kprintf("     :&@@@@@@@@@@@@@@@@@7:.       .B@@@@@@@@@@@@@@@@@@#~:.                               5@@@@@@@@@@@@@@@@@@@7:.            Y@@@@@@@@@@@@@@@@@B!:.       5@@@@@@&7^...................7@@@@@@@@@@@@@@@@@@@Y:.   \n");
    rt_kprintf("     :&@@@@@@@@@@@@@@@@@7:.       .B@@@@@@@@@@@@@@@@@@#~:                                5@@@@@@@@@@@@@@@@@@@7:.          .Y@@@@@@@@@@@@@@@@&5~:.       !@@@@@@@5^:                   .G@@@@@@@@@@@@@@@@@@&!.   \n");
    rt_kprintf("     :&@@@@@@@@@@@@@@@@@7:.       .B@@@@@@@@@@@@@@@@@@#~:.                               5@@@@@@@@@@@@@@@@@@@7:         :?#@@@@@@@@@@@@@@@&P!:.        .#@@@@@@#~:.                    ~@@@@@@@@@@@@@@@@@@@G^.  \n");
    rt_kprintf("     :&@@@@@@@@@@@@@@@@@7:.       .B@@@@@@@@@@@@@@@@@@@#BBBBBBBBBBBBBBBBBBBBBBBBBBB7.    5@@@@@@@@@@@@@@@@@@@Y7!!!!!7?5G&@@@@@@@@@@@@@@@BY!:..         Y@@@@@@@?^.                      Y@@@@@@@@@@@@@@@@@@@?:. \n");
    rt_kprintf("     :&@@@@@@@@@@@@@@@@@7:.       .B@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J:.   5@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#GY7^:.           ~@@@@@@@P^:                       :#@@@@@@@@@@@@@@@@@@#~. \n");
    rt_kprintf("     :&@@@@@@@@@@@@@@@@@?:.       .B@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J:.   5@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&#BPY?!^:..             .B@@@@@@#!:.                        7@@@@@@@@@@@@@@@@@@@5:.\n");
    rt_kprintf("     .7?JJJJJJJJJJJJJJJ?~.         !??JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ~:.   ~??JJJJJJJJJJJJJJJJJJJJJJJJJJ???77!~^^:...                  :7??JJJJ!:.                         .7?JJJJJJJJJJJJJJJJJ?:.\n");
    rt_kprintf("                                                                                                                                                                                                                \n");
    // rt_kprintf("                                                                                                                                                                                                                \n");
    // rt_kprintf("                                                                                                                                                                                                                \n");
    // rt_kprintf("^555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555~. \n");
    // rt_kprintf("!@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J:.\n");
    // rt_kprintf("^55PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP7:.\n");
    // rt_kprintf(" .............................................................................................................................................................................................................. \n");
}

void logo_pcl(void)
{
    rt_kprintf("                                                                                  &&&&&&############&&&&&&&                                                                                 \n");
    rt_kprintf("                                                                       &&###BBGGGGGPPPPPPPPPPPPPPPPPPPPPPGGGGGBBB##&&&                                                                      \n");
    rt_kprintf("                                                                &&#BBGGGPPPPPPPPPPPPPPPPPPPPPGGPPPPPPPPPPPPPPPPPPPPPPGGGB##&&                                                               \n");
    rt_kprintf("                                                          &&#BGGPPPPPPPPPPPPPPPPPPPPPPPPGGGGG5JPGGGGGPPPPPPPPPPPPPPPPPPPPPPPGGBB#&                                                          \n");
    rt_kprintf("                                                      &#BGGPPPPPPPPPPPPPPPPPPPPPPPPPPPP5T7TTT~ ~T777T5GPPPPPPPPPPPPPPPPPPPPPPPPPPPGGB#&                                                     \n");
    rt_kprintf("                                                 &&BGGPPPPPPPPGPPGGPPPPPPPPPPPPPPPPPPPGJ 77~TJ7~TTT~ TGPPPPPPPPPPPPPPPPPPPPGGGPPPPPPPPPGB#&                                                 \n");
    rt_kprintf("                                              &#GGPPPPPPPPPPG57T!!YPPPPPPPPPPPPPPPPPPPP5T55!~5~:PGG575GPPPPPPPPPPPPPPPPPPGJ!7Y5PPPPGGPPPPPPGB#&                                             \n");
    rt_kprintf("                                          &#BGPPPPPPPPPPPPGGG5^.~:^YGPPPPPPPPPPPPPPPPPPGP!~JPP:^GGGGGGPPPPPPPPPPPPPPPPPPGP7JJ::5GGG55PPPPPPPPPPGB&                                          \n");
    rt_kprintf("                                       &#BGPPPPPPPPPPG7^PGY!~~!!.JGJYGPPPPPPPPPPPPPPPPGYTT~!J7 ~JTTTTYGPPPPPPPPPPPPPPPPG5^!PT^YPYT~.~GPPPPPPPPPPPPGB&                                       \n");
    rt_kprintf("                                     #BGPPPPPPPPPPPPPPP:^J7.~5YT!:Y~^PPPPPPPPPPPPPPPPPPYJJJT^ ~!^!TJJYPPPPPPPPPPPPPPPPGY:~P!^7~^^75!:5GPPPPPPPPPPPPPPGB&                                    \n");
    rt_kprintf("                                  &BGPPPPPPPPPPPPPPPPGJ^..JY.:7^~T:::PPGPPPPPPPPPPPPPPPPJT!^~JGYT!~~TPPPPPPPPPPPPPPPPPP5T7~ T55J!!!7.^5PPPPPPPPPPPPPPPPPG#&                                 \n");
    rt_kprintf("                                #GPPPPPPPPPPPPPPPPPPPPPP5:!GY.JP^!Y..5J!PPPPPPPPPPPPPPPP77J5GGPGGGPJ7PPPPPPPPPPPPPPPGT!!7J7:Y~!G7Y5JY75PPPPPPPPPPPPPPPPPPPGB&                               \n");
    rt_kprintf("                             &BGPPPPPPPPPPPPPPPPPPPPPPPPG5:!T^.Y~:Y:^^~.5GPPPPPPPPPPPPPPGGGGPPPPPPGGGPPPPPPPPPPPPPPPPPJYY^^PP:YT:5T^YGPPPPPPPPPPPPPPPPPPPPPPPG#                             \n");
    rt_kprintf("                           &BGPPPPPPPPPPPPPPPPPPPPPPPPPPPP~ ~J.!5P~^PPY5PPPPPPGGGGGGGGPPPPPPPPPPPPPPPPGGGGGGGGPPPPPPPPT!~7T!7JPJ!~75PPPPPPPPPPPPPPPPPPPPPPPPPPPG#                           \n");
    rt_kprintf("                         &BPPPPPGGGGGPPPPPPPPPPPPPPPPPPPG5!YGP^TGPPPPPGGGGGGPP5YJT7!~^^:::........:::^^~!7TJY5PPGGGGGPGGPGPYT!~:.7PGPPPPPPPPPPPPPPPPPPPGGGPPPPPPPG#                         \n");
    rt_kprintf("                       &BPPPPPPPY55!75GPPPPPPPPPPPPPPPPPPPGGPPPPPPGGGGP5JT!^:.                                .:^!TJ5PGGGGGGGGP5JT5PPPPPPPPPPPPPPPPPPPPY!TPGPPPPPPPG#                       \n");
    rt_kprintf("                      BGPPPPPGPG7.^7!^75GGGPPPPPPPPPPPPPPPPPPPGGGP5J!^:                                             .:^!J5PGGGPGGGPPPPPPPPPPPPPPPPPPPGY:7~:TPPPPPPPPPG#                     \n");
    rt_kprintf("                    #GPPPPPGPT^!7~~~TJ:!57YPGPPPPPPPPPPPPPGGGPYT~:                            ...                         :~TYPGGGPPPPPPPPPPPPPPPPGPPPP!^JJ^^^~GPPPPPPPG&                   \n");
    rt_kprintf("                  &BPPPPPPPJ7~~T!^!!~7T!^7^~YGPPPPPPPPPGGG5J~:                      .~!7!:   ^777!.   :~!~.                   :!J5GGGPPPPPPPPPGGPP5PT:^!^.^JJ::JGGPPPPPPPB                  \n");
    rt_kprintf("                 #GPPPPPPP!.77!!~:7!!!~TY!~J^~PPPPPPPGG5T^.          .:^!77.:!7!!:  ^TTTT~   ~777!.  .7TTT~                      .~T5GGPPPPPPPTTP5^^YY~:75J:^JT:~YPPPPPPPPG&                \n");
    rt_kprintf("               &BPPPPPPPPPPJ!!.~!!!!.!!7~TPP~!PPPPGGPT~.          :^!7TTJJ: !T77T~   ^^~^     .::.    .^^:                          .~JPGGPPPPJ^^JPJ:~^~7~!.!^T!.7PPPPPPPPPPB               \n");
    rt_kprintf("              #GPPPPPPPPPPPGPY!!7^^~~7JT~TPPPGPPGGY!.         .:~7TTTTTY5P!..^~!^   .   .::.     ..                                    .!YGGPPGPJ^^!:~:~5P~ 5PPY5GPPPPPPPPPPPG&             \n");
    rt_kprintf("             #PPPPPPPPPPPPPPPGG57:7J7~^77!PPPPGPJ~          :!7TTTTTTY5PPPP5YJ. :^^:   .!777~   .!!!^                                     ~JPGPPGPT::YP7:75YPPPGGPPPPPPPPPPPPPG&            \n");
    rt_kprintf("            BPPPPPPPPPPPPPPPPPPGGPT~JT:T5GPPGPJ^         .~7TTTTTTTJ5PPPPPPP5! ~T7T7^  .!777~.  ^777~                                       ^JPGPPGPT:~55YPGPPPPPPPPPPPPPPPPPPPP#           \n");
    rt_kprintf("           GPPPPPPPPPPPPPPPPPPPPPPG5!JPGPPGGJ^         :!TTTTTTTTJ5PPPPPPPPPY  :!77!.    .:.   .....                                          ^YGGPPGP7^5GPPPPPPPPPPPPPPPPPPPPPPP#          \n");
    rt_kprintf("          GPPPPPPPPPPPPPPPPPPPPPPPPGGPPPPG5~         :7TTTTTTTTTY5PPPPPPPPPPPY7!!:   .     .....                                                ~5GPPPGPPPPPPPPPPPPPPPPPPPPPPPPPPPB         \n");
    rt_kprintf("         GPPPPPPPPPPPPPPPPPPPPPPPPPPPPPGP7.        :!TTTTTTTTTTY5555PPPPPPPPPPPP5::!77!:. .!77!.                                                 .7PGPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPB        \n");
    rt_kprintf("        BPPPPPPPPPPPPPPPPPPPPPPPPPPPPPGY^        .!TTTTTTTTTTJ55555555PPPPPPPPPP^ ^7777:  .~77~.                                                   ^5GPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP#       \n");
    rt_kprintf("       BPPPPPPPPPPPPPPPPPPPPPPPPPPPPPGT.        ^TTTTTTTTTTTJ55555555555PPPPPPPPY~^~^:.                                                             .JGPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP#      \n");
    rt_kprintf("      #PPPPPPPPPPPPPPPPPPPPPPPPPPPPGP!        .!TTTTTTTTTTTJY5555555555555PPPPPPPPY7.                                                                 7PGPPPPPPPPPPPPPPPPPPPPPPPPPPPPG&     \n");
    rt_kprintf("     &PPPPPPPPPPPPPPPPPPPPPPPPPPPPGP~        :7TTTTTTTTTTJJY555555555555555PP5J7^.      ..::::^^^^::..                                                 ~PGPPPPPPPPPPPPPPPPPPPPPPPPPPPPG     \n");
    rt_kprintf("     GPPPPPPPPPPPPPPPPPPPPPPPPPPPGP^        :TTTTTTTTTTJJJY55555555555555P5J!:     :^!7JJYYYYY5555555YJT7~:.                                            ~PGPPPPPPPPPPPPPPPPPPPPPPPPPPPPB    \n");
    rt_kprintf("    #PPPPPPPPPPPPPPPPPPPPPPPPPPPGP~        ^TTTTTTTTTJJJJJY555555555555PY7:    .~7JY555YYYYYYYYYY55555PPPP5YJ!:                                          ~PPPPPPPPPPPPPPPPPPPPPPPPPPPPPP&   \n");
    rt_kprintf("   &GPPPPPPPPPPPPPPPPPPPPPPPPPPPG!        :TTTTTTTTJJJJJJY555555555555Y!.   .~TY555YYYYYYYYJJYYYYYYYY5555555PP5Y!:                                        !GPPPPPPPPPPPPPPPPPPPPPPPPPPPPB   \n");
    rt_kprintf("   BPPPPPPPPPPPPPPPPPPPPPPPPPPPGT        :TTTTTTJJJJJJJJJYYYY555555557.   :7Y5555YYYYYYYJJJTJJJJJJJYYYYYY55555PPP5T^                                       TGPPPPPPPPPPPPPPPPPPPPPPPPPPPP&  \n");
    rt_kprintf("  &GPPPPPPPPPPPPPPPPPPPPPPPPPPGY.       .7TTTTTJJJJJJJJJYYYYYYY5555J:   .75P5YJJJTT7777777TJJJJJJJJJJYYYYY55555P5PPPJ^                                     .5GPPPPPPPPPPPPPPPPPPPPPPPPPPPB  \n");
    rt_kprintf("  #PPPPPPPPPPPPPPPPPPPPPPPPPPPP~        ~JTTJJJJJJJJJJJJYYYYYYYYY5T.   ^JJT77!!!!!!!!!~~~~!TTTTJJJJJJJJTTTJJJYY55PPPP5!                                     ~GPPPPPPPPPPPPPPPPPPPPPPPPPPPP& \n");
    rt_kprintf("  GPPPPPPPPPPPPPPPPPPPPPPPPPPGJ        .TJJJJJJJJJJJJJJJYYYYYYYY57..^~~!!!!!!!!!!!!!!!!!!!~77777!!!!~~~~~~~~~~~~!TY5PPPJ:                                    YGPPPPPPPPPPPPPPPPPPPPPPPPPPPB \n");
    rt_kprintf(" &PPPPPPPPPPPPPPPPPPPPPPPPPPPP^        !JJJJJJJJJJJJJJJYYYYYYYYJT!!!7!!!!!!!!!!!!!!!!!!!!!~~~~~~~~~~~~~~~~~~~~~~^^^!YPPPY:                      :!!!^        ~GPPPPPPPPPPPPPPPPPPPPPPPPPPPG \n");
    rt_kprintf(" #PPPPPPPPPPPPPPPPPPPPPPPPPPGY        .TJJJJJJJJJJJJJYYYYYYJT77!!7!!!!!!!!!!!!!!!!!!!!!!!!~~~~~~~~~~~~~~~~~~~~~~~~~^!5PPPY.                     ~77T!        .5GPPPPPPPPPPPPPPPPPPPPPPPPPPG&\n");
    rt_kprintf(" BPPPPPPPPPPPPPPPPPPPPPPPPPPG7        ^JJJJJJJJJJJJYYYYYJT7777777!!!!!!!!!!!!!!!!!!!!!!!!!~~~~~~~~~~~~~~!!!!!!!~^^^~JPPPPP!               .      .^:          TGPPPPPPPPPPPPPPPPPPPPPPPPPPP#\n");
    rt_kprintf(" GPPPPPPPPPPPPPPPPPPPPPPPPPPG~        ~JJJJJJJJJJYYYYYJT777777777!!!!!!!!!!!!!!!!!!!!!!!!!~~~~~~~~~!!7TJJJYYYYYY7!TYPPPPPP5:            .!77~      .          ~GPPPPPPPPPPPPPPPPPPPPPPPPPPP#\n");
    rt_kprintf(" GPPPPPPPPPPPPPPPPPPPPPPPPPPP:        7JJJJJJJJYYYYYJ777777777777!!!!!!!!!!!!!!!!!!!!!!!!!~~~~~!77TJJJJYJYYYY555555Y5PPPPPP~            :777~    :!7!~.       :PPPPPPPPPPPPPPPPPPPPPPPPPPPPB\n");
    rt_kprintf("&GPPPPPPPPPPPPPPPPPPPPPPPPPG5.        7JJJJJJYYYYYJ77777777777777!!!!!!!!!!!!!!!!!!!!!!!!~~~!7TJJJJJJJYYYYYYY55555555PP5PPP7      ..  ..  ..     ~TTT7.       :PGPPPPPPPPPPPPPPPPPPPPPPPPPPB\n");
    rt_kprintf("&GPPPPPPPPPPPPPPPPPPPPPPPPPG5.        7YJJJYYYYYJT777777777777777!!!!!!!!!!!!!!!!!!!!!!!~!7TJJJJJJJJJJYYYYYYY55555555PPPP557     ~777:    .^.  ...:^^.        .5GPPPPPPPPPPPPPPPPPPPPPPPPPPB\n");
    rt_kprintf("&GPPPPPPPPPPPPPPPPPPPPPPPPPG5.        7YJYYYYYYJ77777777777777777!!!!!!!!!!!!!!!!!!!!!~!7JJYJJJYJJYYYYYYYYYY555555555P55PPP~     ~77!.   ~777!.               :5GPPPPPPPPPPPPPPPPPPPPPPPPPPB\n");
    rt_kprintf(" GPPPPPPPPPPPPPPPPPPPPPPPPPPP:        !YYYYYYYT777777777777777777!!!!!!!!!!!!!!!!!!!!!TJYYYJYYYYYYYYYYYYYYYY555555555Y55PP5:            .^777!.. ^!7!~.       :PPPPPPPPPPPPPPPPPPPPPPPPPPPPB\n");
    rt_kprintf(" GPPPPPPPPPPPPPPPPPPPPPPPPPPG^        ^YYYYYYT7777777777777777777!!!!!!!!!!!!!!!!!!!7JYYYYYYYYYYYYYYY555555Y55555555555PPPT      .^^:..    ..   .7T7T7:       ~GPPPPPPPPPPPPPPPPPPPPPPPPPPP#\n");
    rt_kprintf(" BPPPPPPPPPPPPPPPPPPPPPPPPPPG7        .JYYYYJ77777777777777777777!!!!!!!!!!!!!!!!!7J5YYYYYYYYYYYY5Y55555555Y5555555555PPPY.   . :7TTT^   .:.  ....^~^.        7GPPPPPPPPPPPPPPPPPPPPPPPPPPP#\n");
    rt_kprintf(" #PPPPPPPPPPPPPPPPPPPPPPPPPPGY         !YYYYT77777777777777777777!!!!!!!!!!!!!!!!T555YY55Y55555555555555555555P5555555PP5:   ^5J.~!!~: .!777!.   ...          YGPPPPPPPPPPPPPPPPPPPPPPPPPPG&\n");
    rt_kprintf(" &PPPPPPPPPPPPPPPPPPPPPPPPPPPP^        :YYYJ7T7777777777777777777!!!!!!!!!!!!!!!Y5555YY555555555555555555555555555555PPY:   :5PPT~^~7Y!.!777~  ^777!:        ^PPPPPPPPPPPPPPPPPPPPPPPPPPPPG \n");
    rt_kprintf("  GPPPPPPPPPPPPPPPPPPPPPPPPPPGJ         !5YJ7T7777777777777777777!!!!!!!!!!!!!7Y55555555555555555555555555555555555PPPT.   ^5PPPPPPPPP5^ ..^~^ !T777~        JGPPPPPPPPPPPPPPPPPPPPPPPPPPP# \n");
    rt_kprintf("  #PPPPPPPPPPPPPPPPPPPPPPPPPPPP^        .J5J7T7777777777777777777!!!!!!!!!!!!75PPP55PPP555555555PPP5555555P555PP5PPPY^    !5PPPPPPPPPPP5JTJ5PP^ :^^^.       ^PPPPPPPPPPPPPPPPPPPPPPPPPPPPP& \n");
    rt_kprintf("  &GPPPPPPPPPPPPPPPPPPPPPPPPPPGY         :YY7T7777777777777777777!!!!!!!!!!!7555PPPPP5PP5PPP5555PPPPPPPPPPPPPPPPPPY~    ^JPP55PPPPPPPPPPPPPPPP57~^!T~      .YGPPPPPPPPPPPPPPPPPPPPPPPPPPPB  \n");
    rt_kprintf("   BPPPPPPPPPPPPPPPPPPPPPPPPPPPG7         ^YT77777777777777777777!!!!!!!!!!!^!YPPPPPPPPP55PPPPPPPPPPPPPPPPPPPPP5T^    :T5P555555PPPPPPPPPPPPPPP5JJJ7.      7GPPPPPPPPPPPPPPPPPPPPPPPPPPPP&  \n");
    rt_kprintf("   &GPPPPPPPPPPPPPPPPPPPPPPPPPPPP~         ~JT7777777777777777777!!!!!!!!!!:   :!J5PPPPPP55PPPPPPPPPPPPPPPP5Y7^.   .^T555555555555PPPPPPPPPPPYJTTT7.      ~PPPPPPPPPPPPPPPPPPPPPPPPPPPPPB   \n");
    rt_kprintf("    #PPPPPPPPPPPPPPPPPPPPPPPPPPPGP^         ^TT777777777777777777!!!!!!!!!77~.    .^!TJY5PPPPPPPPPPP555YT!^:    .^7Y55555555555555555PPPPP5YJTTTT!.      ^PGPPPPPPPPPPPPPPPPPPPPPPPPPPPP&   \n");
    rt_kprintf("     GPPPPPPPPPPPPPPPPPPPPPPPPPPPG5:         :7T77777777777777777!!!!!!!!!YP5JT!^.      .:^^~~~~~~^^:..     .:~7Y55555555555555555555PP5YJTTTTTT~       ^PGPPPPPPPPPPPPPPPPPPPPPPPPPPPPB    \n");
    rt_kprintf("     &PPPPPPPPPPPPPPPPPPPPPPPPPPPPG5^         .!T77777777777777777!!!!!!!7PPPP55YJT7!^:..             .:^~!TJY55555555555555555555555YJJTTTTTTT^       ^PGPPPPPPPPPPPPPPPPPPPPPPPPPPPPG     \n");
    rt_kprintf("      #PPPPPPPPPPPPPPPPPPPPPPPPPPPPGP~          ^77777777777777777!!!!!!!TPPPPPPP55YYYYJJTTT7777777TTJJYYYYYYYYYYYY55555555555555YYJJTTTTTTTT!.       ~PGPPPPPPPGGPPPPPPPPPPPPPPPPPPPG&     \n");
    rt_kprintf("       BPPPPPPPPPPPPPPPPGGGPPGPPPPPPGP7          .~777777777777777!!!!!!!JPPPPPPPPP5555YYYYYYYYYYYYYYYYYYYYYYYYYYYYY5555555YYYJJJTTTTTTTTTT7^        7PGPPPPPPPG5JGGPPPPPPPPPPPPPPPPP#      \n");
    rt_kprintf("        BPPPPPPPPPPPPGGP5T!^~PGPPPPPPPGJ:          :!7777777777777!!!!!!!YPPPPP555555555555YYYYYYYYYYYYYYYYYYYYYYYYYYYYYJJJJJTTTTTTTTTTTTT~.       :YGPPPPPPPPGG5~!PGPPPPPPPPPPPPPPP#       \n");
    rt_kprintf("         GPPPPPPPPPP5T!~.!5P7^PPPPPPPPPGP!           :!77777777777!!!!!!!YPPP555555555555555YYYYYYYYYYYYYYYYYYYJJJJJJJJJJJJJJTTTTTTTTTTT~.        !PGPPPPPPPPPYTJJ~:T5PPPPPPPPPPPPP#        \n");
    rt_kprintf("          GPPPPPPPPG57YPJ~7T~~PGGPPPPPPPGGJ^           :~777777777!!!!!!!JP555555555555555YYYYYYYYYYYYYYYYYJJJJJJJJJJJJJJJJTTTTTTTTTT7~.        ^YGPPPPPPPPGGPYJJJJT!~~5GPPPPPPPPP#         \n");
    rt_kprintf("           BPPPPPPPPPGGPGPYJ5GPT7PGPPPPPPPGPT:           .^!777777!!!!!!!755555555555555YYYYYYYYYYYYYYYYYJJJJJJJJJJJJJJJJTTTTTTTTTT!^.        :TPGPPPPPPPPG5!!!7PGGGGP5PPPPPPPPPP#          \n");
    rt_kprintf("            BPPPPPPPPPPPPGGPJ~^77^JPPPPPPPPPGP7:            :~!7777!!!!!!!Y5555555555YYYYYYYYYYYYYYYYYYJJJJJJJJJJJJJJJTTTTTTTTTT7~.         :TPGPPPPPPPPPP7:JG5.!YY5PPGPPPPPPPPG#           \n");
    rt_kprintf("             #PPPPPPPPPPGY~~77^JGY!5GGPPPPPPPPGPT:             :^!!77!!!!!755555555YYYYYYYYYYYYYYYYYYJJJJJJJJJJJJJJJTTTTTTTTT!^.          :TPGPPPPPPPPGGGPJ!~7^!T7775PPPPPPPPPG&            \n");
    rt_kprintf("              &GPPPPPPPPP5~~5G5JPGGPTTPPPPPPPPPPGPJ~.             .:~!!!!!!7Y5555YYYYYYYYYYYYYYYYYYJJJJJJJJJJJJJJJJTJJJTT7~:.          .~JPGPPPPPPPPPG5JJYPGPT~~75GGPPPPPPPPPB&             \n");
    rt_kprintf("               &BPPPPPPPPGGT!PGGGY7~.~GGPPPPPPPPPPGG57:               .:^~!!7J555YYYYYYYYYYYYYYYYJJJJJJJJJJJJJJJJJJT7!~:.            :75GGPPPPPPPPPP5!~TT!^!5GG5JYGPPPPPPPPP#               \n");
    rt_kprintf("                 #GPPPPPPPPGPPPJ~~JT^PP7!5GPPPPPPPPPGGPY!:                 .::~7TJYYYYYYYYYYYYYYYYJJJJJJJJJJTT7!~^:.              :7YPGGPPPPPPPPGGPGT 5GGGP7:5GPGGPPPPPPPPG&                \n");
    rt_kprintf("                  &BPPPPPPPPPP57YG5:T7^75GGPPGGPPPPPPPPGGPY7^.                   .::^~~!777TTTTTTT777!!~~^^:..                .^7YPGGPPPPPPPPPGPY!JGP!^T5PPT:5GPPPPPPPPPP#                  \n");
    rt_kprintf("                    #GPPPPPPPPPGGP~.~JPG57!!!!JPPPPPPPPPPPGGG5J!^.                                                        .^!J5GGGPPPPPPPPPPP5T~.!PGGGY7!!!75GPPPPPPPPPB&                   \n");
    rt_kprintf("                      #GPPPPPPPPPPYYPGGT:75PP5~TGPGGGPPPPPPPPGGGP5J7~:.                                              .:~7Y5PGGGPPPPPPPPPPGPGGJT5Y~^JGGGGGPPGGPPPPPPPPG#                     \n");
    rt_kprintf("                       &BPPPPPPPPPGGPPP:!BP775PPGP5Y5PGPPPPPPPPPPGGGGP5YT!^:.                                  .:~!TY5PGGGGPPPPPPPPPPPPPGT^7YPGGGGJ^~YPPPPPPPPPPPPPG#                       \n");
    rt_kprintf("                         &BPPPPPPPPPPPGJ^7J~^YGP7^!77~TPPGGPPPPPPPPPPPGGGGGP55YT7!~^^::....      ....::^^~!7TY5PPGGGGGPPPPPPPPPPPGGPPPGPGJ:T7^!YPGGPJJPPPPPPPPPPPG#                         \n");
    rt_kprintf("                           &BGPPPPPPPPPGPJTJPGP^^5GGG5JPGJJPPPGPPPPPPPPPPPPPPGGGGGGGPPPP555555555555PPPPGGGGGGGPPPPPPPPPPPPPPPPPPYT77~!PPG7^T~7!~JPPGGPPPPPPPPPG#                           \n");
    rt_kprintf("                             &#GPPPPPPPPPGGGPG5 TGGPPGGGT.JGGPJ5PPGGGGPPPPPPPPPPPPPPPPPPGGGGGGGGGGGGPPPPPPPPPPPPPPPPPPPPPGPPPPGG5:^5GJ JGGP:^PGG5PPPPPPPPPPPPG#                             \n");
    rt_kprintf("                                #GPPPPPPPPPPPPPJ~!7YGPG7.^TY5~:5GP7TY5PPPPGPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPGGGGGPPPPT!!!~TPG5^^!!^!J5GY7PPPPPPPPPPPPPGB&                               \n");
    rt_kprintf("                                  &BGPPPPPPPPPPGP55PPP!:YPY7.^PGG7.JJ77PG5JPPPGGPPPPGGGGPPPPPPPPGPPPPPPPPGGPPPPP5YJTYPPG!:5PP5^^PGP~:YPY7TPGGPPPPPPPPPPPG#&                                 \n");
    rt_kprintf("                                     #BGPPPPPPPPPPGPPPT5GG5^~PGGJ.~7TPPPG! !GGJ!PPGPYJJY5PPPPPPP5PPPPPPPPTTPPPGT.TYJ.TGG7.5GGG5 JGPG7TPGGGPPPPPPPPPPPGB&                                    \n");
    rt_kprintf("                                        #BGPPPPPPPPPPPGGPGY7PGGY.7P5YPPGY.T:YP:!GGY^~JJTTPPPPPG5.YGPPPPGT:~!PGPP:~T7^!JPP7:7JJ~~5GPPGGPPPPPPPPPPPPGB&                                       \n");
    rt_kprintf("                                           &BGPPPPPPPPPPPPGGPPGY!7!7YGPG~^G7^T.5GP:~GPYY5PPPPPG5.TGPPPPP^!5:~PGGT JPP!.5GG5JTJYPGPPPPPPPPPPPPPGG#&                                          \n");
    rt_kprintf("                                              &#BGPPPPPPPPPPPPPGGPP55PG5~YGP^ 7GPP^^PPY^^PPPPPPP.7GGGPGY.!TT^^5GP~^777YPPPGGGGGPPPPPPPPPPPPGB#&                                             \n");
    rt_kprintf("                                                  &#BGPPPPPPPPPPPPPGPPPPPPPG5JPPPG5!~77^TGPPPPPP:^T775GT^PGGP7YGPP5PPGGPPPPPPPPPPPPPPPPGB#&                                                 \n");
    rt_kprintf("                                                      &#BGGPPPPPPPPPPPPPPPPPGGPPPPGGP55PGPPPPPPP55555PPPPPPPPGGPPPPPPPPPPPPPPPPPPPGBB#&                                                     \n");
    rt_kprintf("                                                           &#BBGGPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPGGGGPPPPPPPPPPPPPPPPPPPPPPPPGGB##&                                                          \n");
    rt_kprintf("                                                                &&#BBGGGPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPGGBB##&                                                                \n");
    rt_kprintf("                                                                       &&&##BBBGGGGGPPPPPPPPPPPPPPPPPPPPPGGGGGBBB##&&                                                                       \n");
    rt_kprintf("                                                                                   &&&&&&###########&&&&&&                                                                                  \n");
}

void logo_ict(void)
{
    rt_kprintf("                                                                                         .....::::::::::.....                                                                           \n");
    rt_kprintf("                                                                              ..:^^~!!7777JJJYYYYYYYYYYYYYYYYYYJJJ7777!!~^::.                                                              \n");
    rt_kprintf("                                                                      .:^~!77JJYYY5555555YYYYYYYYYYYYYYYYYYYYYYYYYY5555555YYYJJ7!~^:.                                                      \n");
    rt_kprintf("                                                                .^~!7JYYY5555YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY5555YYJ7!~:.                                                \n");
    rt_kprintf("                                                          .:~!7JYY555YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY555YYJ7!^.                                           \n");
    rt_kprintf("                                                      :^!7JY555YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY55YYJ7~:                                       \n");
    rt_kprintf("                                                 .:~7JY55YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY55555555555YYYYYYYYYYYYYYYYYYYY555YJ7~.                                   \n");
    rt_kprintf("                                              :~7JY55YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY55555YYYYYJJJJ77777777777777JJJJYYYY55555YYYYYYYYYY55Y7!:                                \n");
    rt_kprintf("                                          .^7JY55YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY555YYYJJ77!~^^::...                    ...:^^~!77JJYY5555YYYYYY5YJ7^.                            \n");
    rt_kprintf("                                       .~7Y55YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY555YYJ77~^:..                                           ..:^!77JYY55YYYY5YJ!:                          \n");
    rt_kprintf("                                    .~7Y55YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY555YJ7!~:.                                                          .:^!7JYY55YY5Y7~.                       \n");
    rt_kprintf("                                 .~7Y55YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY55YJ7!^:                                                                      .^!7YY5555Y7:                     \n");
    rt_kprintf("                               ^7Y55YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY55YJ7~:.                                                      .:^~!777JJJJJJJ7777!~^:..^!7YY55Y7^                   \n");
    rt_kprintf("                            .~JY5YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY5YJ7~:                                                     .^!7Y5PGGGGGGGGGGGGGGGGGGGGGGP5J7!~!7JY5Y7^                 \n");
    rt_kprintf("                          :!Y5YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY5YJ!^.                                                    .~7YPPP5YJ7!~^^::::::::^^^~!77J5PPGGGGGPYJJJYYY7:               \n");
    rt_kprintf("                        :7Y5YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY5YJ!:                                                     :7YP5J7~:.                         .:^!7YPGGGGP5555Y7.             \n");
    rt_kprintf("                      :7Y5YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY5YJ!:                                                     :!YYJ!:                                     .^!JPGGGGPP5Y~            \n");
    rt_kprintf("                    :7Y5YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY5Y7^                                                      ^7J7^                                             .~75GGGGP57.          \n");
    rt_kprintf("                  .7Y5YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY5YJ~.                                                      ^77^                                                   .~JPGGGPY^         \n");
    rt_kprintf("                 ~Y5YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY5Y7^                                                       :!~.                                                        :7PGGGP!        \n");
    rt_kprintf("               :75YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY5Y7^                                                        :^.                                                            :JGGGG7       \n");
    rt_kprintf("              !Y5YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY7^                                                                                                                           ^5GGGJ.     \n");
    rt_kprintf("            :75YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYJ^                                                                                                                              .JGGGY.    \n");
    rt_kprintf("           ^YY^.::::::::::::::::::::::::::......                                                                                                                                  7GGGY.   \n");
    rt_kprintf("          !YY77777777777777777777777:    .!!!!!!!!!!!!!!!!!7^         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^        .!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!^    7GGGJ   \n");
    rt_kprintf("         755Y555555555555555555555Y~    :YGGGGGGGGGGGGGGGGGY:       .JGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG5^       :YGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG5.    JGGG!  \n");
    rt_kprintf("       .757::::::::::::::::::::::::    ^PGGGGGGGGGGGGGGGGG7        :5GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGY:       ^5GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG7    .5GG5. \n");
    rt_kprintf("      .75J~^^^^^^^^^^^^^^^^^^^^^.     !PGGGGGGGGGGGGGGGGG7        ^PGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG7.       !PGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG5.    !GGG! \n");
    rt_kprintf("      75555555555555555555555557.    7GGGGGGGGGGGGGGGGGP~        ~PGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG7        7GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG^    .5GGY \n");
    rt_kprintf("     !5J!!!!!!!!!!!!!!!!!!!!!!~    .JGGGGGGGGGGGGGGGGG5^        7GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGP~       .JGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG7     JGGP:\n");
    rt_kprintf("    ~YY~ ...................      :YGGGGGGGGGGGGGGGGGY:        7GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG5:       :5GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGJ     7GGG^\n");
    rt_kprintf("   :Y5YYYYYYYYYYYYYYYYYYYYY7:    ^5GGGGGGGGGGGGGGGGGJ.       .JGGGGGGGGGGGGGGGGGGYYYYYYYYYYYYYYYYY5GGGGGGGGGGGGGGGGGGGY.       ~PGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG5.    !GGG~\n");
    rt_kprintf("   75YJJJJJJJJJJJJJJJJJJJJ7:    ~PGGGGGGGGGGGGGGGGG7        :5GGGGGGGGGGGGGGGGGG7                ^5GGGGGGGGGGGGGGGGGG7        .!!!!!!!!7GGGGGGGGGGGGGGGGGGGGJ!!!!!!!!!!!!!!!!!!!~     !GGG^\n");
    rt_kprintf("  ^Y5~                         7GGGGGGGGGGGGGGGGGP!        ^PGGGGGGGGGGGGGGGGGG!                ~PGGGGGGGGGGGGGGGGGP!                 ^5GGGGGGGGGGGGGGGGGGG7     .................:::.7GGP:\n");
    rt_kprintf("  75Y7777777777777777777:    .7GGGGGGGGGGGGGGGGGP^        ~PGGGGGGGGGGGGGGGGGP~                 ::::::::::::::::::::                 7GGGGGGGGGGGGGGGGGGGP~    :YGPPPPPPPPPPPPPPPPPPPPPGG5.\n");
    rt_kprintf(" :YYYYYYYYYYYYYYYYYYY5Y~    .YGGGGGGGGGGGGGGGGG5:        7GGGGGGGGGGGGGGGGGG5^                                                     .JGGGGGGGGGGGGGGGGGGG5:    .75YYYYYYYYYYYYYYYYYYYYYPGGJ \n");
    rt_kprintf(" !5Y~.::::::::::::::::.    ^5GGGGGGGGGGGGGGGGGJ.        7GGGGGGGGGGGGGGGGGG5:                                                     :YGGGGGGGGGGGGGGGGGGGJ.                            :PGG! \n");
    rt_kprintf(".J5Y~^^^^^^^^^^^^^^~.     ~PGGGGGGGGGGGGGGGGG7        .JGGGGGGGGGGGGGGGGGGY.                                                     ^PGGGGGGGGGGGGGGGGGGG7     !YYYYYYYYYYYYYYYYYYYYYYYJ5GGP. \n");
    rt_kprintf(":YYY5555555555555557.    7GGGGGGGGGGGGGGGGGG!        :5GGGGGGGGGGGGGGGGGGJ.                                                     !PGGGGGGGGGGGGGGGGGGP~    .7GGGGGGGGGGGGGGGGGGGGGGGGGGGG7  \n");
    rt_kprintf("^Y5J~~~~~~~~~~~~~!^     7GGGGGGGGGGGGGGGGGP~        ^PGGGGGGGGGGGGGGGGGG7                                                      7GGGGGGGGGGGGGGGGGGG5^      :::::::::::::::::::::::::7GGP:  \n");
    rt_kprintf("~557.............     .YGGGGGGGGGGGGGGGGG5:        ~PGGGGGGGGGGGGGGGGGG!                                                     .YGGGGGGGGGGGGGGGGGGGY.    :!!~~~~~~~~~~~~~~~~~~~~~~~~~5GG7   \n");
    rt_kprintf("~5YYYYYYYYYYYYY7:    :5GGGGGGGGGGGGGGGGGY.        7GGGGGGGGGGGGGGGGGGP~                ^7777777777777777777.                ^5GGGGGGGGGGGGGGGGGGG7     !PGGGGGGGGGGGGGGGGGGGGGGGGGGGGG5.   \n");
    rt_kprintf("~5YYJ7777777JJ7.    ~PGGGGGGGGGGGGGGGGG7.        7GGGGGGGGGGGGGGGGGG5^                !PGGGGGGGGGGGGGGGGGP~                ~PGGGGGGGGGGGGGGGGGGG!     .!7!!!!!!!!!!!!!!!!!!!!!!!!!JGGP^    \n");
    rt_kprintf("~YYJ.              !GGGGGGGGGGGGGGGGGG7        .JGGGGGGGGGGGGGGGGGGG7~!!!!!!!!!!!!!!~7GGGGGGGGGGGGGGGGGG5:                7GGGGGGGGGGGGGGGGGGGP^     :...........................:YGG!     \n");
    rt_kprintf(":YYY77777777:     7GGGGGGGGGGGGGGGGGP~        :5GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGY.               .JGGGGGGGGGGGGGGGGGGGY:    :YGPPPPPPPPPPPPPPPPPPPPPPPPPPPPGG7      \n");
    rt_kprintf(".JYYYYYYYYY^    .JGGGGGGGGGGGGGGGGG5^        ^PGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGJ.               :YGGGGGGGGGGGGGGGGGGGJ.    .J5YYYYYYYYYYYYYYYYYYYYYYYYYY5GGGJ       \n");
    rt_kprintf(" 75YJ:...:.    :5GGGGGGGGGGGGGGGGGY:        ~PGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG7                ~PGGGGGGGGGGGGGGGGGGG7                                  .JGGJ        \n");
    rt_kprintf(" ~5YY!~~:     ^PGGGGGGGGGGGGGGGGGJ.        7GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG!                !GGGGGGGGGGGGGGGGGGGP~     7YJJJJJJJJJJJJJJJJJJJJJJJJJJJJ5GG7         \n");
    rt_kprintf(" .J5Y557.    !GGGGGGGGGGGGGGGGGG7        .7GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGP~               .JGGGGGGGGGGGGGGGGGGG5:    .7GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG7          \n");
    rt_kprintf("  ^YYYJ.    :777777777777777777~         75YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY^                ^77777777777777777777.      ::::::::::::::::::::::::::::7PGP~           \n");
    rt_kprintf("   ~YYY7:                                                                                                                                ~777777777777777777777777777777777PGY:            \n");
    rt_kprintf("    ~YYYY~                                                                                                                             ^YGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG7.             \n");
    rt_kprintf("     ~55Y57:                                                                ..                                                       ^JGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG5^               \n");
    rt_kprintf("      ^55YYY7:                                                            :^:                                                      ~YGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGP7.                \n");
    rt_kprintf("       :JP5YYY7~.                                                       ^!~.                                                    .!YGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGJ:                  \n");
    rt_kprintf("         7PP5YYYJ7^.                                                 :!7~.                                                    ^7PGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGY^                    \n");
    rt_kprintf("          ^YGP5YY55J7~:                                          .^777^.                                                   :!YGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGY~                      \n");
    rt_kprintf("            !PGP5YYY55YJ7~^.                                .:~7JJ7~.                                                   :!JPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGY~                        \n");
    rt_kprintf("             .7PGPY77JYY555YJ77~^::..               ..:^~!7JYYJ7^.                                                   :!YPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPJ^                          \n");
    rt_kprintf("               :JGGG5J!~!77YY55555YYJJ777777777777JJYYYYYJ7~^.                                                   .^75PGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGP7:                            \n");
    rt_kprintf("                 :7PGGGPJ!^:::~!777JJYYYYYYYYYYJJ777!~^:.                                                    .^7YPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGY!.                              \n");
    rt_kprintf("                   :75GGGGG5J!:.     ..........                                                         .:~7YPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG57:                                 \n");
    rt_kprintf("                     .!YGGGGGGGPY7~:.                                                              .:~7J5PGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG57^.                                   \n");
    rt_kprintf("                        :75GGGGGGGGGPY77~:.                                                 .:^~7JYPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG57^.                                      \n");
    rt_kprintf("                           ^75GGGGGGGGGGGGP5Y77!~^:..                             ..:^^!77JY5PGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPY7^.                                         \n");
    rt_kprintf("                             .^75PGGGGGGGGGGGGGGGGPP55YYJ7777!!!!!!~~!!!!!7777JYY55PPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG5J!:                                             \n");
    rt_kprintf("                                 :!J5GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG5J!:.                                                \n");
    rt_kprintf("                                    .^!J5GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPY7~:.                                                    \n");
    rt_kprintf("                                        .:!7YPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPY7!^.                                                         \n");
    rt_kprintf("                                             .^~7J5PGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPYJ7~:.                                                              \n");
    rt_kprintf("                                                   .^~77Y5PPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGP5YJ7!^:.                                                                    \n");
    rt_kprintf("                                                          .:^~!7JJY55PPGGGGGGGGGGGGGGGGGGGGGGGGGGGPP55YJJ7!~^:..                                                                           \n");
    rt_kprintf("                                                                    ..::^^~~!!!!777777777!!!~~~^^::..                                \n");
}

void logo_ysyx(void)
{
    rt_kprintf("                                                                                     ..                                           \n");
    rt_kprintf("                                                                                     !YPPYJ!^                                       \n");
    rt_kprintf("                                                                   :                 :5GGGGGG7:                                     \n");
    rt_kprintf("                                                                  ?G?.                 ?GGGGGGG?.~!:                                \n");
    rt_kprintf("                                                                 7GGBY.              :~5GGGGGGGGPBBY                                \n");
    rt_kprintf("                                                                !GGGGG^       .^~!7J5GGGGGGGGGGGGP5Y:                               \n");
    rt_kprintf("                                                               ^PGGGGG^ .:~!?5PGGGBGGGGGGGGGGGJ^:.                                  \n");
    rt_kprintf("                                 ..:^^~~7?7YY!^.              .5GGGGGG5YPGGBGGGGGGGGBGGGGGGGP^.                                     \n");
    rt_kprintf("     ....          ..::^^~!7JJYY55PGGGGGGBBGGBGP?           :JYGGGGGGGGGGGGGGGGGGP5Y7~:~GGGGP:                                      \n");
    rt_kprintf(" .~?YPPPP?!~~!7?JY5PPGGGGGGBGGGGGGGGGGGGGGGBBGG5^           ~BGGGGGGGGGGGGGGP5Y7~..    :GGGGY^....        .!:  :~!!!!!!!!!!!~~~!:   \n");
    rt_kprintf(":PGBGGGGGGGGGGBBGGGGGGGGGGGGGGGGGGBGGGGP5J??7!~             !GGGGGGGGGGP5J!:.          ^GGGGGGPPPP5Y:     ~B7  ?GGGGGGGGGBBBBBBB!   \n");
    rt_kprintf(" !GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGYJ?!^::.                    ?BGGGGBG5?~.               !GGGGGGGGGGB5.     .~:  :~~~~~~~~!?J?????^   \n");
    rt_kprintf("  ?GGGGGGGGGGGGGGGGGGGGGGGGGGGG?                            :^5GG5?^                ^~JGGGGGJ5GGGG5:      ~G7  YGGGGGGGGPPPPPPPP!   \n");
    rt_kprintf("   ^PGGGGGGGGGGGGGGGGGGGGGGGGG7                               .~:.                 ~GBGGGGGG?PGGGGY       :?~  !???????JYGGGGGGG7   \n");
    rt_kprintf("    ^PGGGGGGGGGGGGGGGGGGGGBG57^                                                   ~GGGGGGGGGGGGGGGY.                    ^GGGGGGG7   \n");
    rt_kprintf("     :5GGGGGGGGGGGGGBGGPYJ7^                                                     7GGGGGGGGGGGGGGPY.                     ^GGGGGGG7   \n");
    rt_kprintf("       :7PGBBBGGGP5J7~:.                                                        ^GGGGGGGGGGGGGGG7.                      ^GGGGGGG7   \n");
    rt_kprintf("         .~7?7~~^.                                                              7GGGGGGGGGGGGGGG??~                     :PGGGGGG7   \n");
    rt_kprintf("                                                                                .PGGGGGGGGGGP7~:                        .PGGGGGG7   \n");
    rt_kprintf("                                                                                 ~GGGGGGGGG5^                           .PGGGGGG7   \n");
    rt_kprintf("                                                                              .^~7PGGGGGGGGPJJJJ?!.                     .GGGGGGB7   \n");
    rt_kprintf("                                                                              :GGGGGGGGGGGGGBGGGBBPYJY^                 .?5GGG5J~:^ \n");
    rt_kprintf("                                                                              ^GGGGBGGGGGGGGGGGBGGGPPG7              .!   7GGG^ .GG:\n");
    rt_kprintf("                                                                              ^Y55Y7!!~~~^^^^^!7~^:. .               :?   7GGG^ :GG:\n");
    rt_kprintf("                                                                        .                                            :?   7GGG^ :GG:\n");
    rt_kprintf("                                                                      :YP?:               !^                         :?   7GGG^ :GG:\n");
    rt_kprintf("                                                                      JBGBG?.            ?B5                         :?   7GGG^ :GG:\n");
    rt_kprintf("                                                                     :GGGGGB5.         ^5GGGY^....::..               ^J   7GGG^ :GG:\n");
    rt_kprintf("                                                                     :PGGGGGBY.  ..^~!YGGGGGGGPPPPPGPP5~             ^J   7GGG: :GG:\n");
    rt_kprintf("                                                                     :PGGGGGGG555PPGGBGGGGGGGGGBBBBGGPJ~             ^J   7GGG: :GG:\n");
    rt_kprintf("                                                               :^~?J55GGGGGGGGGGGGGGGGGGGBGGP55YYJ?~^.               ^J   7GGG: :GG:\n");
    rt_kprintf("                                                          .~?J5GGGBGGGGGGGGGGGGGGGGGGGG5?!~:.                        ^J   7GGG: :GG:\n");
    rt_kprintf("                                   .:~!!!!!~.             ^YGBBBGGGGGGGGGGGGGGPP5GGGG5!                              ~J   7GGG: :GG:\n");
    rt_kprintf("                       .^~~~~!7?JY5PGGGGGGGGPJ~             .^7JYY55YYJ5GGGPY!.:7G57:                                ~J   7GGG: :GG:\n");
    rt_kprintf("   !J?7~~^^^^::^!7??JJ5PGGGGGGBGGGGGGGGGGGGGGGGY:                      .^~^.   :7^                                   ~J   7GGG: :GG:\n");
    rt_kprintf("   JBBBGGGGGGGGGGBBGGGGGGGGGGGGGGGGGGGGGGGGGGGGBP~                                                                   ~J   7GGG: :GG:\n");
    rt_kprintf("   .?5GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGP?                                                   .               ~J   7GGG: :GG:\n");
    rt_kprintf("      ^5BGGGGGGGGGGGGGGGGGGGGGGGGGGBP55YJ?!~^^::.                      .~:      :~:.           .~7JY55YJ?7!~^.       ~Y   ?GGG: :GG:\n");
    rt_kprintf("       .7PGGGGGGGGGGGGGGGGGGGGGBGPY!:                                .?PY:      :5P5YY?7!~~~~!?5PPPPPPPPPPPPPPJ:     ~Y   ?GGG: :GG:\n");
    rt_kprintf("         :YGGGGGGGGGGGBBGGGGGG5J!:                                  ~5GJ.        .?PGPPPPPPPPPPPPPPPPPPPPPPPPPG5.    ~Y   ?GGG: :GG:\n");
    rt_kprintf("           ^YPGBGGGPYJ?7YBBP?^.                                    ?PP5.           :?5PPPPPPPPPPPPPPPPP5YYYYYJ?~     ~Y   ?GGG: :GG:\n");
    rt_kprintf("             :~7!~:.  .!5Y7.                                     .JPPP?              .!5PPPPPPPPP5YJ7^:.             ~Y   ?GGG: :GG:\n");
    rt_kprintf("                    .~7~.                                       .JPPPP~   .::..        .75PPPPPPJ!^.                 ~Y   ?GGG: :GG:\n");
    rt_kprintf("                    :.                                         :YPPPPP:   ?PPP5Y?7~^^::::~5PPPPPPPP55Y?~.            ~Y   JGGG: :GG:\n");
    rt_kprintf("                                                              ~5PPPPP5.    ~YPGPPPPPPPPPPPPPPPPPPPPPPGGG?            ~Y   JGGG: :GG:\n");
    rt_kprintf("                                                            :JPPPPPPPY       ^?5PPPPPPPPPPPPPPPPPPPPYJ7~.            ~Y   JGGG: :GG:\n");
    rt_kprintf("                           ..   ...                         7GPPPPPPP?         .:~7?JYYYYY5YYYJ?7~^.                 ~Y   JGGG: :GG:\n");
    rt_kprintf("                          .YY: ~55Y.                        !PPPPPPPP~                                               ~Y   JGGG: :GG:\n");
    rt_kprintf("                          .7?: ^???.                        :5GPPPPP5.                                               ~Y   JGGG: :GG:\n");
    rt_kprintf("                          :GB! 7BGG:                         .?5PPPP!                                                ~Y   JGGG: :GG:\n");
    rt_kprintf("                          :PG~ !GGG:                           .:~~:                                                 ~Y   JGGG: :GG:\n");
    rt_kprintf("                          :PG~ !GGG^   .                                                                             ~Y   YGGG: :GG:\n");
    rt_kprintf("                          :GG~ !GGG5YYYPP55555555YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY5555555555555555555555PPYY5PGGG: :PG:\n");
    rt_kprintf("                          :GG~ !GGGJ777J?7777777777777777777777777777777777777777777777777777777777777777777777777777Y5!775GGG: :PG:\n");
    rt_kprintf("                          :GG^ !GGG?!!!J?7!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!77J5!!!5GGG: :PG:\n");
    rt_kprintf("                          :GG^ !GGGGBBBGGBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGGBBBGGGG: :PG:\n");
    rt_kprintf("                          .^^. .^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^.  :^ \n");
    rt_kprintf("                                                                                                                                    \n");
    rt_kprintf("                           ~^   ::^^^^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^::::::::...    ~~ \n");
}

void logo(void)
{
    logo_ieda();
    logo_pcl();
}
// void tmp_cpu_test(void)
// {
//     rt_kprintf("[%14s] %sPASS!%s\n", "shift", COLOR_GREEN, COLOR_NONE);
//     rt_kprintf("[%14s] %sFAIL!%s\n", "shift", COLOR_RED, COLOR_NONE);
//     if (hello_str_main())
//     {
//         rt_kprintf("[%14s] %sPASS!%s\n", "hello-str", COLOR_GREEN, COLOR_NONE);
//     }
//     else
//     {
//         rt_kprintf("[%14s] %sFAIL!%s\n", "hello-str", COLOR_RED, COLOR_NONE);
//     }
// }
void cust_delay(int val)
{
    for(int i = 0; i < val; ++i)
        for(int j = 0; j < 1e9; ++j);
}

void test()
{
    // logo_ict();
    // cust_delay(100);
    // logo_ysyx();
    // cust_delay(100);
    cpu_test();
    rt_kprintf("\n\n");
    cust_delay(100);
    dhmk();
    rt_kprintf("\n\n");
    cust_delay(100);
    mimk();
    rt_kprintf("\n\n");
    cust_delay(100);
    comk();
    rt_kprintf("\n\n");
    cust_delay(100);
}

// MSH_CMD_EXPORT(logo_ieda, print ieda logo);
// MSH_CMD_EXPORT(logo_pcl, print pcl logo);
// MSH_CMD_EXPORT(logo_ict, print ict logo);
// MSH_CMD_EXPORT(logo_ysyx, print ysyx logo);
// MSH_CMD_EXPORT(logo, print logo);
// MSH_CMD_EXPORT(cpu_test, run cpu test);
// MSH_CMD_EXPORT(dhmk, run dhrystone);
// MSH_CMD_EXPORT(comk, run coremark);
// MSH_CMD_EXPORT(mimk, run microbench);
// MSH_CMD_EXPORT(test, run tests);

int main(void)
{
    rt_kprintf("Hello RISC-V!\n");
    // thread_sample();
    // cpu_test();
    // dhmk();
    // comk();
    // mimk();
    return 0;
}
