#include <stdio.h>
#include <libxml/parser.h>

/*gcc `xml2-config --cflags --libs` test.c*/
/*
int is_leaf(xmlNode * node)
{
  xmlNode * child = node->children;
  while(child)
  {
    if(child->type == XML_ELEMENT_NODE) return 0;

    child = child->next;
  }

  return 1;
}

void print_xml(xmlNode * node, int indent_len)
{
    while(node)
    {
        if(node->type == XML_ELEMENT_NODE)
        {
          printf("%*c%s:%s\n", indent_len*2, '-', node->name, is_leaf(node)?xmlNodeGetContent(node):xmlGetProp(node, "id"));
        }
        print_xml(node->children, indent_len + 1);
        node = node->next;
    }
}
*/
int main(){
  xmlDoc *doc = NULL;
  xmlNode *root = NULL;

  doc = xmlReadFile("input.xml", NULL, 0);

  if (doc == NULL) {
    printf("Could not parse the XML file");
  }

  root = xmlDocGetRootElement(doc);

  xmlNode* child = root->children->next;
  printf("The root's child's name is %s\n", (char*)child->name);
 // print_xml(root_element, 1);
  xmlNode* test = child->children->next;
  while(test!=NULL)
 {
 	 printf("The root's  name is %s\n", (char*)test->name);
 	 printf("That grandchild's contents are %s\n", (char*)test->children->content);
	test=test->next->next; 
}
  xmlFreeDoc(doc);

  xmlCleanupParser();
}
