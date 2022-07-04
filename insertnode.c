#include <stdio.h>
#include <libxml/parser.h>

/*gcc `xml2-config --cflags --libs` test.c*/

xmlNode * find_node(xmlNode * node, char * name) {
  xmlNode * result;
  
  if (node == NULL) return NULL;
  
  while(node) {
    if((node->type == XML_ELEMENT_NODE) && (strcmp(node->name, name) == 0)) {
      return node;
    }
    if(result = find_node(node->children, name)) return result;
    node = node->next;
  }
  
  return NULL;
}

void add_node(xmlNode *root, char* id, char* author, char* title) {
  xmlNode* node = find_node(root, "Database");
  xmlNode* new_node = NULL;
  xmlNode* new_child_node = NULL;
  
  if(node == NULL) return;
  new_node = xmlNewNode(NULL, BAD_CAST "User_2");
  xmlSetProp(new_node, "id", id);
  
  new_child_node = xmlNewNode(NULL, BAD_CAST "UniqueID");
  xmlNodeSetContent(new_child_node, "1879");
  xmlAddChild(new_node, new_child_node);
  
  new_child_node = xmlNewNode(NULL, BAD_CAST "Name");
  xmlNodeSetContent(new_child_node, "Abinaya");
  xmlAddChild(new_node, new_child_node);
  
  new_child_node = xmlNewNode(NULL, BAD_CAST "Age");
  xmlNodeSetContent(new_child_node, "21");
  xmlAddChild(new_node, new_child_node);
  
  new_child_node = xmlNewNode(NULL, BAD_CAST "Gender");
  xmlNodeSetContent(new_child_node, "F");
  xmlAddChild(new_node, new_child_node);
  
  new_child_node = xmlNewNode(NULL, BAD_CAST "PhoneNumber");
  xmlNodeSetContent(new_child_node, "9003340750");
  xmlAddChild(new_node, new_child_node);
  
  new_child_node = xmlNewNode(NULL, BAD_CAST "Height");
  xmlNodeSetContent(new_child_node, "123");
  xmlAddChild(new_node, new_child_node);
  
  new_child_node = xmlNewNode(NULL, BAD_CAST "Weight");
  xmlNodeSetContent(new_child_node, "78");
  xmlAddChild(new_node, new_child_node);
  
  new_child_node = xmlNewNode(NULL, BAD_CAST "Password");
  xmlNodeSetContent(new_child_node, "AravinthK");
  xmlAddChild(new_node, new_child_node);
  
  xmlAddChild(node, new_node);
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

int main(){
  xmlDoc *doc = NULL;
  xmlNode *root_element = NULL;

  doc = xmlReadFile("input.xml", NULL, 0);

  if (doc == NULL) {
    printf("Could not parse the XML file.\n");
    return 1;
  }

  root_element = xmlDocGetRootElement(doc);

  add_node(root_element, "bk500", "F. Scott Fitzgerald", "The Great Gatsby");
  
  save_to_file(doc, "input.xml");
  
  xmlFreeDoc(doc);

  xmlCleanupParser();
  
  return 0;
}
