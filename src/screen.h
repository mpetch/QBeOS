class Screen {
        private:
        // VideoMemory is the address of the video memory to write to
        unsigned short* VideoMemory=(unsigned short*)0xb8000;

        // Screen management vars
        const short rowCount = 24;
        const short colCount = 80;
        const short format = 0x0002;
        const char whiteSpace = 0x0020;
        int currCursorPos = 0;

        // Debug vars

        // debug enables using this library to debug it self
        bool _Ddebug = false;
        int _DcallCounts = 0;


        public:
        void ClearScreen();

        void ScrollUp();

        void WriteString(const char* stringPtr);

        void WriteCharacterToScreen(const char characterToPrint);

        void WriteIntToScreen(int num);

        void _DenableSelfDebug();

};
