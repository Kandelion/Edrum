#ifndef __SONG_DATA__
#define __SONG_DATA__
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

#include "../../edrum-hardware/Hardware_IO/NoteData.hpp"

class SongData
{
	// � ���̴� �巳 ����
	int drum_amount;
	// ���� ��� �����ϰ� �ִ� ��Ʈ
	int current_note;
	// � ���̴� ��Ʈ ����
	int note_amount;
	
	std::fstream song;
	
	//���ϸ��� ������ID_���̸�_�۰.sdd �� �����Ѵ�.
	std::string filename;
	inline void set_filename() 
	{
		filename = std::string(ID) + "_" + std::string(name) + "_" + std::string(artist) + ".sdd";
	};

	// �����κ��� ��Ÿ�����͸� �о�´�.
	bool read_header();
	// ���� ��Ÿ�����͸� DataFIle�� ����.
	bool write_header();

	// ���Ϸκ��� NoteData �ϳ��� �о�´�.
	bool read_note(NoteData& note);
	// ���Ϸκ��� NoteData �ϳ��� ����.
	bool write_note(const NoteData& note);

	//������ ����.
	bool open(std::string filename);
	// ������ �����.
	bool create(std::string filename);
	// ������ �ݴ´�.
	void  close();

	//���ο� �ִ� ��� ������ �ʱⰪ���� �ʱ�ȭ�Ѵ�.
	void clear();

public:

	//server���� ���̴� id
	int server_id; //4byte
	 // local���� �ο��Ǵ� id
	int local_id; //4byte
	// �� �̸�
	char name[51]; //51byte
	// �۰
	char artist[51];
	// ��¥ ������ ǥ��
	char date[16];
	// ���� ������ ����� ID
	char ID[21];

	const static int metadata_size;

	

	SongData()
	{
		this->clear();
		
	}

	// SongData ���ο� �ִ� ���ϸ��� �����´�.
	inline std::string& get_filename()
	{
		return filename;
	}

	/* filename�� �ش��ϴ� ������ �о� ��Ÿ�����͸� �����Ѵ�. */
	/* ������ ������ false�� �����Ѵ�. */
	bool pre_read(char* filename);
	/* filename�� �ش��ϴ� ������ �о� ��Ÿ�����͸� �޾ƿ� ��,
	Note �������� list�� �ִ´� */
	bool read(std::vector<NoteData>& notelist);
	
	/* MetaData�� �����Ѵ�.*/
	bool pre_write(int local_id, std::string name, std::string artist, std::string ID, int drum_amount, int note_amount);
	/* ���� �ִ� MetaData�� �������� ������ ���� */
	bool write(const std::vector<NoteData>& notelist);
};

#endif