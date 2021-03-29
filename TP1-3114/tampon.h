struct instruction {
	char oP;
	int file;
};

struct block {
	bool dirty = (false);
	int file;
    int ite = 0;
    //block *suiv, *prev; 
};

class bassin {
public:
	bassin();
	~bassin();

	void readFile(int file, int &compteur);
	void modifyFile(int file);
	void writeFile(int file);
	void closeBuffer();
	void closeFile(int file);
	int fileInBuffer(int file);
	void markDirty(int block);
	bool isFull(int compteur);
    static void returnTime(int file, int &lastfile, int &timer);
	block tampons[5];
    int compteur = 0;
    int less = 0;
    int indiceH1 = 0;
    int lessUsed();
    int lastFile = -1;
    int timer = 0;
    int H = 0;
    int full=-1;
};

class HDD{
public:
    void readFileHDD(int file);
    void modifyFileHDD(int file);
    void reset(int &lastFileHDD, int &timerHDD);
    //void writeFileHDD(int file);
    friend class bassin;   
    
    int lastFileHDD=-1;
    int timerHDD=0;
private:
 
};
