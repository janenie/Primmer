OBJS = Item_base.o Bulk_item.o Sales_item.o  Basket.o chapter16.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

res: $(OBJS)
		$(CC) $(LFLAGS) $(OBJS) -o res
		
Item_base.o: Item_base.h Item_base.cc
		$(CC) $(CFLAGS) Item_base.cc

Bulk_item.o: Bulk_item.h Bulk_item.cc Item_base.h Item_base.cc
		$(CC) $(CFLAGS) Bulk_item.cc
		
Sales_item.o: Sales_item.h Sales_item.cc Item_base.h Item_base.cc
		$(CC) $(CFLAGS) Sales_item.cc
		
Basket.o: Basket.h Basket.cc Item_base.h Item_base.cc Sales_item.h Sales_item.cc
		$(CC) $(CFLAGS) Basket.cc


chapter16.o: chapter16.cc Sales_item.h Sales_item.cc Item_base.h Item_base.cc Basket.h Basket.cc Bulk_item.h Bulk_item.cc
		$(CC) $(CFLAGS) chapter16.cc

		
clean:
	\rm *.o *~ res
