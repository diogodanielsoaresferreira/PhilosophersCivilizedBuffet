/**
 *  \brief Waiter data structures
 *  
 * \author Miguel Oliveira e Silva - 2016
 *         Ana Patrícia Gomes da Cruz
 *         Diogo Daniel Soares Ferreira
 *         João Pedro de Almeida Maia
 *         
 */


#ifndef WAITER_H
#define WAITER_H
typedef enum {
   W_NONE,                           // waiter initial state
   W_SLEEP,                          // waiter sleeping (waiting for requests)
   W_REQUEST_CUTLERY,                // waiter processing a request for clean cutlery
   W_REQUEST_PIZZA,                  // waiter processing a request for pizza meals
   W_REQUEST_SPAGHETTI,              // waiter processing a request for spaghetti meals
   W_DEAD                            // waiter is dead
} WaiterState;

typedef enum {
   W_INACTIVE,                       // no pending request
   W_ACTIVE                          // a pending request is active
} WaiterPendingState;

typedef enum {
   FORK,
   KNIFE
} Fork_Knife;

typedef struct _Cutlery_Request_{
   int id;                          // Id of philosopher that requested
   Fork_Knife request;              // Type of request
   int num;                         // Number of requests or number of philosophers
} Cutlery_Request;

typedef struct _Waiter_ {
   WaiterState state;                           // current waiter state
   WaiterPendingState reqCutlery;               // waiter's request cutlery state
   WaiterPendingState reqPizza;                 // waiter's request pizza state
   WaiterPendingState reqSpaghetti;             // waiter's request spaghetti state
   Cutlery_Request *reqCutleryPhilosophers;     // Array with philosophers' id of cutlery requests
   int *reqPizzaPhilosophers;                   // Array with philosophers' id of pizza requests
   int *reqSpaghettiPhilosophers;               // Array with philosophers' id of spaghetti requests
   int cutlery_number_ups_without_request;      // Number of up's of cutlery without request
   int pizza_number_ups_without_request;        // Number of up's of pizza without request
   int spaghetti_number_ups_without_request;    // Number of up's of spaghetti without request
} Waiter;

void init_waiter(void);

void waiter_life(void);



#endif
