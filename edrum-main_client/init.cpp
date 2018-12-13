#include "init.hpp"

using namespace std;

void init_main_client(ResourceManager *pRM, LocalList **LL, ServerList **SL, MyList **ML){
    cout<<"client init"<<endl;
    if(pRM){
        if(!pRM->initialize()){
            std::cerr << " *** ResourceManager INIT FAILED!!" << std::endl;
            exit(0);
        }
        cout<<"pRM initialized"<<endl;
        *LL = pRM->getLocallist();

        cout<<"LL get from pRM"<<endl;
        SongData *pSD = nullptr;

        (*LL)->print();

        for(int i=0; i<SONGLIST_SIZE; i++){
            pSD = (*LL)->getSong(i);
            cout<<"pSD get from LL - "<<i<<endl;

            cout << "pSD : " << *(int*)(pSD) << endl;
            cout << "pSD->name : " << *(int*)(pSD->name) << endl;
            if(pSD->name[0] == 0)
            {
                cout << "pLabel : " << *(int*)(pLabel_songlist_title[i]) << endl;
                pLabel_songlist_title[i]->set_text("");
                pLabel_songlist_uploader[i]->set_text("");
                pLabel_songlist_artist[i]->set_text("");
                pLabel_songlist_date[i]->set_text("");
                continue;
            }
            cout<<"set list label - "<<i<<endl;

            pLabel_songlist_title[i]->set_text(pSD->name);
            pLabel_songlist_uploader[i]->set_text(pSD->ID);
            pLabel_songlist_artist[i]->set_text(pSD->artist);
            pLabel_songlist_date[i]->set_text(pSD->date);
        }
    }
}

int get_widget_pointer(){
    refBuilder->get_widget("entry_pw", pEntry_pw);
    refBuilder->get_widget("entry_id", pEntry_id);
    refBuilder->get_widget("box_login", pBox_login); 
    refBuilder->get_widget("list_song", pListBox_song);
    refBuilder->get_widget("stack_main", pStack_main);
    refBuilder->get_widget("label_notice", pLabel_notice);

    char widget_name[15] = "listitem_song0";
    char label_title[27] = "label_listitem_song_title0";
    char label_uploader[] = "label_listitem_song_uploader0";
    char label_artist[] = "label_listitem_song_artist0";

    // Initialize List widget.
    for (int i = 0; i < SONGLIST_SIZE; i++)
    {
        widget_name[strlen(widget_name) - 1] = '0' + i;
        label_title[strlen(label_title) - 1] = '0' + i;
        label_uploader[strlen(label_uploader) - 1] = '0' + i;
        label_artist[strlen(label_artist) - 1] = '0' + i;

        try
        {
            refBuilder->get_widget(widget_name, pListItem_song[i]);
            std::cout << "Item " << i << " : " << pListItem_song[i] << std::endl;
            if(pListItem_song[i] == nullptr){
                throw "Not exist songlist item.";
            }
            refBuilder->get_widget(label_title, pLabel_songlist_title[i]);
            refBuilder->get_widget(label_uploader, pLabel_songlist_uploader[i]);
            refBuilder->get_widget(label_artist, pLabel_songlist_artist[i]);
            pListBox_song->append(*pListItem_song[i]);
        }
        catch(const char *e)
        {
            std::cout << "Error : " << e << std::endl;
            return -1;
        }
    }

    // Init main page.
    pStack_main->set_visible_child("page_login");

    return 0;
}