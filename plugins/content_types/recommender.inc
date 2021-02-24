  <?php
/**
 * @file
 * This plugin generates a search result based on a new materials node. It's
 * mainly used to override the default page for this node type (node/%node).
 */

$plugin = array(
  'title' => t('Ting Recommender'),
  'description' => t('Show recommendation'),
  'single' => TRUE,
  //'edit form' => 'ting_inspiration_list_content_type_edit_form',
  'render callback' => 'ting_recommender_content_type_render',
  'category' => t('Ting'),
  'required context' => array(
    new ctools_context_optional(t('Ting object'), 'ting_object'),
    new ctools_context_optional(t('Ting collection'), 'ting_collection'),
  ),
  'render last' => TRUE,
);

/**
 * Render the ting new materials results results amount block.
 */
function ting_recommender_content_type_render($subtype, $conf, $panel_args, $context) {
  // Define the return block.
  $block = new stdClass();

  drupal_add_js('https://cdn.bibspire.dk/ddbcms.js', 'external');

  $pid = NULL;

  // Ting object context.
  if (!empty($context[0]->data)) {
    /** @var \TingEntity */
    $object = $context[0]->data;
    $pid = $object->getId();
  }
  // Ting collection context.
  elseif (!empty($context[1]->data)) {
    /** @var \TingCollection */
    $collection = $context[1]->data;
    $pid = $collection->getId();
  }

  $data = '';
  if (isset($pid)) {
    $data = "data-ting-object-id='$pid'";
  }

  // Set block content.
  $block->content = '<a name="recommender"></a><div id="ting-recommender" ' . $data . '></div>';
  return $block;
}


