Req's -
  Create block
    right sidebar
    title - Hello World! (bold)
    list linked node titles to nodes of type 'hello world article' tagged with 'enabled' terms from the 'Sections' vocabulary
      appearing only on Hello World Article pages
  All Hello World Articles should have "Content starts here!" in italics on first line.


  Identify styles and create css
  Identify machine names of vocabulary and content type
  Check for sidebar second

  EntityFieldQuery for DB calls

Keep in mind
  Bartik must be theme (or theme with sidebar right)

Identify relevant hooks

First list published nodes of type HWA
Look for Sections term (value)
Ensure term is enabled - if not, query will skip node

Do not list current node

Checking whether a field exists or not has been added to entityFieldQuery in Drupal 8, but unfortunately won't be backported to Drupal 7.

Roadmap:
  Create block - hook_block_info
    Define and add default settings
      Theme
      Region

  Build block container - hook_block_view
    Insert content function

  Generate content - hook_block_content
    Find available nodes
    Look for Section field value
    Run query if Section has value
    Ensure current node is not queried and doesn't show in list
    Execute
    Override block title ($block[subject])
    List node titles
      With links to node

  Add content teaser to hello_world_article node types only - hook_node_view

    Styles
      Add classes to fields - hook_theme
        block[subject]
        $title
