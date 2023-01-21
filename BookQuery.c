#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_paraS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};
struct document get_document(char* text) {
    size_t curr_letter =0, curr_word =0, curr_sentence =0, curr_para = 0;
    struct document Doc;
    Doc.data = (struct paragraph*)malloc(sizeof(struct paragraph));
    Doc.data[0].data = (struct sentence*)malloc(sizeof(struct sentence));
    Doc.data[0].data[0].data = (struct word*)malloc(sizeof(struct word));
    Doc.data[0].data[0].data[0].data = (char*)malloc(sizeof(char));
    for (size_t i = 0; i < strlen(text); i++)
    {
        if (text[i] == '\n')
        {
            if(i == strlen(text) - 1) break;
            curr_para++;
            curr_letter = curr_word = curr_sentence = 0; 
            Doc.data = (struct paragraph*)realloc(Doc.data, sizeof(struct paragraph) * (curr_para + 1) );
            Doc.paragraph_count = curr_para;
            Doc.data[curr_para].data = (struct sentence*)malloc(sizeof(struct sentence));
            Doc.data[curr_para].sentence_count = 0;
            Doc.data[curr_para].data[curr_sentence].word_count=0;
            Doc.data[curr_para].data[curr_sentence].data = (struct word*)malloc(sizeof(struct word) * 1);
            Doc.data[curr_para].data[curr_sentence].data[curr_word].data = (char*)malloc(sizeof(char) * 1);   
        }
        else if(text[i] == '.') 
        {
            Doc.data[curr_para].data[curr_sentence].word_count++;
            curr_sentence++;
            curr_letter = curr_word = 0;
            Doc.data[curr_para].data = (struct sentence*)realloc(Doc.data[curr_para].data, sizeof(struct sentence) * (curr_sentence + 1));
            Doc.data[curr_para].sentence_count = curr_sentence;
            Doc.data[curr_para].data[curr_sentence].word_count = 0;
            Doc.data[curr_para].data[curr_sentence].data = (struct word*)malloc(sizeof(struct word));
            Doc.data[curr_para].data[curr_sentence].data[curr_word].data = (char*)malloc(sizeof(char));
            
        }
        else if(text[i] == ' ')
        {
            curr_letter = 0;  
            curr_word++;
            Doc.data[curr_para].data[curr_sentence].word_count = curr_word;
            Doc.data[curr_para].data[curr_sentence].data = (struct word*)realloc(Doc.data[curr_para].data[curr_sentence].data, sizeof(struct word) * (curr_word + 1));
            Doc.data[curr_para].data[curr_sentence].data[curr_word].data = (char*)malloc(sizeof(char));
        }
        else
        {
            Doc.data[curr_para].data[curr_sentence].data[curr_word].data = (char*)realloc(Doc.data[curr_para].data[curr_sentence].data[curr_word].data, sizeof(char) * (curr_letter + 2));
            Doc.data[curr_para].data[curr_sentence].data[curr_word].data[curr_letter++] = text[i];
            Doc.data[curr_para].data[curr_sentence].data[curr_word].data[curr_letter] = '\0';
        }
    }   
    return Doc;
}

struct word kth_word_in_mth_sentence_of_nth_para(struct document Doc, int k, int m, int n) {
    return Doc.data[n-1].data[m-1].data[k-1];
}

struct sentence kth_sentence_in_mth_para(struct document Doc, int k, int m) { 
    return Doc.data[m-1].data[k-1];
}

struct paragraph kth_para(struct document Doc, int k) {
    return Doc.data[k-1];
}


void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_para(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_para(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_paraS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_para(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_para(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_para(Doc, k);
            print_para(para);
        }
        printf("\n");
    }     
}
/*struct document get_document(char* text) {
    size_t curr_letter =0, curr_word =0, curr_sentence =0, curr_paragraph = 0;
    struct document doc;
    doc.data = (struct paragraph*)malloc(sizeof(struct paragraph));
    doc.data[0].data = (struct sentence*)malloc(sizeof(struct sentence));
    doc.data[0].data[0].data = (struct word*)malloc(sizeof(struct word));
    doc.data[0].data[0].data[0].data = (char*)malloc(sizeof(char));
    for (size_t i = 0; i < strlen(text); i++)
    {
        if (text[i] == '\n')
        {
            if(i == strlen(text) - 1) break;
            curr_paragraph++;
            curr_letter = curr_word = curr_sentence = 0; 
            doc.data = (struct paragraph*)realloc(doc.data, sizeof(struct paragraph) * (curr_paragraph + 1) );
            doc.paragraph_count = curr_paragraph;
            doc.data[curr_paragraph].data = (struct sentence*)malloc(sizeof(struct sentence));
            doc.data[curr_paragraph].sentence_count = 0;
            doc.data[curr_paragraph].data[curr_sentence].word_count=0;
            doc.data[curr_paragraph].data[curr_sentence].data = (struct word*)malloc(sizeof(struct word) * 1);
            doc.data[curr_paragraph].data[curr_sentence].data[curr_word].data = (char*)malloc(sizeof(char) * 1);   
        }
        else if(text[i] == '.') 
        {
            doc.data[curr_paragraph].data[curr_sentence].word_count++;
            curr_sentence++;
            curr_letter = curr_word = 0;
            doc.data[curr_paragraph].data = (struct sentence*)realloc(doc.data[curr_paragraph].data, sizeof(struct sentence) * (curr_sentence + 1));
            doc.data[curr_paragraph].sentence_count = curr_sentence;
            doc.data[curr_paragraph].data[curr_sentence].word_count = 0;
            doc.data[curr_paragraph].data[curr_sentence].data = (struct word*)malloc(sizeof(struct word));
            doc.data[curr_paragraph].data[curr_sentence].data[curr_word].data = (char*)malloc(sizeof(char));
            
        }
        else if(text[i] == ' ')
        {
            curr_letter = 0;  
            curr_word++;
            doc.data[curr_paragraph].data[curr_sentence].word_count = curr_word;
            doc.data[curr_paragraph].data[curr_sentence].data = (struct word*)realloc(doc.data[curr_paragraph].data[curr_sentence].data, sizeof(struct word) * (curr_word + 1));
            doc.data[curr_paragraph].data[curr_sentence].data[curr_word].data = (char*)malloc(sizeof(char));
        }
        else
        {
            doc.data[curr_paragraph].data[curr_sentence].data[curr_word].data = (char*)realloc(doc.data[curr_paragraph].data[curr_sentence].data[curr_word].data, sizeof(char) * (curr_letter + 2));
            doc.data[curr_paragraph].data[curr_sentence].data[curr_word].data[curr_letter++] = text[i];
            doc.data[curr_paragraph].data[curr_sentence].data[curr_word].data[curr_letter] = '\0';
        }
    }   
    return doc;
}
struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n-1].data[m-1].data[k-1];
}
struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    return Doc.data[m-1].data[k-1];
}
struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k-1];
}*/ 
