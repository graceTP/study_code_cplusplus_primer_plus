#include "StringBad.h"
#include "stacktp.h"
#include "ArrayTP.h"
#include "tempmemb.h"
#include "non-template-friend.h"
#include "bound-template-friend.h"
#include "unbound-template-friend.h"

int main()
{
	// StringBad::StringBad_test();

	/*StackTP<int> st;
	st.StackTP_test();*/

	/*ArrayTP<int,1> at;
	at.ArrayTP_test();*/

	//beta<int> bt;
	//bt.beta_test();

	//HasFriend<int> ht;
	//ht.HasFriend_test();

	//HasFriendT<int> htt;
	//htt.HasFriendT_test();

	ManyFriend<int> mt;
	mt.ManyFriend_test();

}