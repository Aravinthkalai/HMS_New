#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include<libxml/parser.h>
   xmlDoc *doc = NULL;
    xmlNode *root_element = NULL;
void xml_open();
void xml_read();
void xml_close();
void add_node(xmlNode *root, char *UniqueID, char *User_number, char *Name, char *Age,char *Gender, char *PhoneNumber, char *Height, char *Weight, char *Password);

void save_to_file(xmlDoc *doc, char *file_name);

#include"create_user.c"


//struct node *head=malloc(sizeof(struct node));
 

int main()
{
   
 //   xml_open();
  //  add_node(root_element,"1233","user_2","AravinthK","12","M","9003340750","123","50","aravinth");
  //  xml_close();
    xml_read();
  //  xml_close();
    Main_Menu();  
    Get_UserData();


}


void xml_close()
{
   xmlFreeDoc(doc);

   xmlCleanupParser();

}
void xml_read()
{
  unsigned char dummy1[10];
  xml_open();

  xmlNode* child = root_element->children->next;
  printf("The root's child's name is %s\n", (char*)child->name);
 // print_xml(root_element, 1);
  xmlNode* test = child->children->next;
  while(test!=NULL)
 {
 	 printf("The root's  name is %s\n", (char*)test->name);
   strcpy(dummy1,test->name);
 	 printf("That grandchild's contents are %s\n", (char*)test->children->content);
   if(!(strcmp(dummy1,"Password")))
   {
     break;
   }
	 test=test->next->next; 
 }
 
 xml_close();
}

void xml_open()
{
   doc = xmlReadFile("input.xml", NULL, 0);

  if (doc == NULL) {
    printf("Could not parse the XML file.\n");
    return 1;
  }

   root_element = xmlDocGetRootElement(doc);  
}

void add_node(xmlNode *root, char *UniqueID, char *User_number, char *Name, char *Age,char *Gender, char *PhoneNumber, char *Height, char *Weight, char *Password) 
{
  xmlNode* node = find_node(root, "Database");
  xmlNode* new_node = NULL;
  xmlNode* new_child_node = NULL;
  
  if(node == NULL) return;
  new_node = xmlNewNode(NULL, BAD_CAST User_number);
  xmlSetProp(new_node, "id", "12");
  
  new_child_node = xmlNewNode(NULL, BAD_CAST "UniqueID");
  xmlNodeSetContent(new_child_node, UniqueID);
 
  xmlAddChild(new_node, new_child_node);
  
  new_child_node = xmlNewNode(NULL, BAD_CAST "Name");
  xmlNodeSetContent(new_child_node, Name);
  xmlAddChild(new_node, new_child_node);
  
  new_child_node = xmlNewNode(NULL, BAD_CAST "Age");
  xmlNodeSetContent(new_child_node, Age);
  xmlAddChild(new_node, new_child_node);
  
  new_child_node = xmlNewNode(NULL, BAD_CAST "Gender");
  xmlNodeSetContent(new_child_node, Gender);
  xmlAddChild(new_node, new_child_node);
  
  new_child_node = xmlNewNode(NULL, BAD_CAST "PhoneNumber");
  xmlNodeSetContent(new_child_node, PhoneNumber);
  xmlAddChild(new_node, new_child_node);
  
  new_child_node = xmlNewNode(NULL, BAD_CAST "Height");
  xmlNodeSetContent(new_child_node, Height);
  xmlAddChild(new_node, new_child_node);
  
  new_child_node = xmlNewNode(NULL, BAD_CAST "Weight");
  xmlNodeSetContent(new_child_node, Weight);
  xmlAddChild(new_node, new_child_node);
  
  new_child_node = xmlNewNode(NULL, BAD_CAST "Password");
  xmlNodeSetContent(new_child_node, Password);
  xmlAddChild(new_node, new_child_node);
  
  xmlAddChild(node, new_node);
  
  save_to_file(doc, "input.xml");

}

void save_to_file(xmlDoc *doc, char *file_name) {
  xmlChar *xmlbuff;
  int buffersize;
  FILE *fp;
  
  xmlDocDumpFormatMemory(doc, &xmlbuff, &buffersize, 1);
  
  fp = fopen(file_name, "w+");
  fprintf(fp, xmlbuff);
  fclose(fp);
}
