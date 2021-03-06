
#include "GtkTreeSelection.h"

/**
 * Constructor
 */
GtkTreeSelection_::GtkTreeSelection_() = default;

/**
 * Destructor
 */
GtkTreeSelection_::~GtkTreeSelection_() = default;

void GtkTreeSelection_::set_mode(Php::Parameters &parameters)
{
	int int_type = (int)parameters[0];
	GtkSelectionMode type = (GtkSelectionMode)int_type;

	gtk_tree_selection_set_mode (GTK_TREE_SELECTION(instance), type);

}

Php::Value GtkTreeSelection_::get_mode()
{
	GtkSelectionMode ret = gtk_tree_selection_get_mode (GTK_TREE_SELECTION(instance));

	return ret;
}

void GtkTreeSelection_::set_select_function(Php::Parameters &parameters)
{
	// GtkTreeIter *iter;
	// if(parameters.size() > 0) {
	// 	Php::Value object_iter = parameters[0];
	// 	GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
	// 	iter = GTK_WIDGET(phpgtk_iter->get_instance());
	// }

	// gtk_tree_selection_set_select_function (GTK_TREE_SELECTION(instance), iter);

	throw Php::Exception("GtkTreeSelection_->set_select_function() not implemented yet");

}

void GtkTreeSelection_::get_select_function(Php::Parameters &parameters)
{
	// GtkTreeIter *parent;
	// if(parameters.size() > 0) {
	// 	Php::Value object_parent = parameters[0];
	// 	GtkTreeIter_ *phpgtk_parent = (GtkTreeIter_ *)object_parent.implementation();
	// 	parent = GTK_WIDGET(phpgtk_parent->get_instance());
	// }

	// gint position = (gint)parameters[1];

	// gtk_tree_selection_get_select_function (GTK_TREE_SELECTION(instance), parent, position);

	throw Php::Exception("GtkTreeSelection_->get_select_function() not implemented yet");

}

Php::Value GtkTreeSelection_::get_user_data(Php::Parameters &parameters)
{
	// GtkTreeIter *parent;
	// if(parameters.size() > 0) {
	// 	Php::Value object_parent = parameters[0];
	// 	GtkTreeIter_ *phpgtk_parent = (GtkTreeIter_ *)object_parent.implementation();
	// 	parent = GTK_WIDGET(phpgtk_parent->get_instance());
	// }

	// GtkTreeIter *sibling;
	// if(parameters.size() > 1) {
	// 	Php::Value object_sibling = parameters[1];
	// 	GtkTreeIter_ *phpgtk_sibling = (GtkTreeIter_ *)object_sibling.implementation();
	// 	sibling = GTK_WIDGET(phpgtk_sibling->get_instance());
	// }

	// gpointer ret = gtk_tree_selection_get_user_data (GTK_TREE_SELECTION(instance), parent, sibling);

	// return ret;

	throw Php::Exception("GtkTreeSelection_->get_user_data() not implemented yet");
}

Php::Value GtkTreeSelection_::get_tree_view()
{
	GtkTreeView *ret = gtk_tree_selection_get_tree_view (GTK_TREE_SELECTION(instance));

	GtkTreeView_ *return_parsed = new GtkTreeView_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkTreeView", return_parsed);
}

Php::Value GtkTreeSelection_::get_selected(Php::Parameters &parameters)
{
	GtkTreeModel *model;
	if(parameters.size() > 0) {
		Php::Value object_model = parameters[0];
		GtkTreeModel_ *phpgtk_model = (GtkTreeModel_ *)object_model.implementation();
		model = GTK_TREE_MODEL(phpgtk_model->get_model());
	}

	GtkTreeIter iter;

	gboolean ret = gtk_tree_selection_get_selected (GTK_TREE_SELECTION(instance), &model, &iter);
	if(!ret) {
		return false;
	}

	GtkTreeIter_ *return_parsed = new GtkTreeIter_();
    return_parsed->set_instance(iter);
    return Php::Object("GtkTreeIter", return_parsed);
}

Php::Value GtkTreeSelection_::selected_foreach(Php::Parameters &parameters)
{
	// GtkTreeIter *parent;
	// if(parameters.size() > 0) {
	// 	Php::Value object_parent = parameters[0];
	// 	GtkTreeIter_ *phpgtk_parent = (GtkTreeIter_ *)object_parent.implementation();
	// 	parent = GTK_WIDGET(phpgtk_parent->get_instance());
	// }

	// gint position = (gint)parameters[1];

	// GtkTreeIter *ret = gtk_tree_selection_selected_foreach (GTK_TREE_SELECTION(instance), parent, position);

	// GtkTreeIter_ *return_parsed = new GtkTreeIter_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkTreeIter", return_parsed);

	throw Php::Exception("GtkTreeSelection_->selected_foreach() not implemented yet");
}

Php::Value GtkTreeSelection_::get_selected_rows(Php::Parameters &parameters)
{
	GtkTreeModel *model;
	if(parameters.size() > 0) {
		Php::Value object_model = parameters[0];
		GtkTreeModel_ *phpgtk_model = (GtkTreeModel_ *)object_model.implementation();
		model = GTK_TREE_MODEL(phpgtk_model->get_model());
	}

	GList *ret = gtk_tree_selection_get_selected_rows (GTK_TREE_SELECTION(instance), &model);

	Php::Value ret_arr;

	for(int index=0; GList *item=g_list_nth(ret, index); index++) {
		ret_arr[index] = (char *) item->data;
	}

	return ret_arr;
}

Php::Value GtkTreeSelection_::count_selected_rows()
{
	gint ret = gtk_tree_selection_count_selected_rows (GTK_TREE_SELECTION(instance));

	return ret;
}

void GtkTreeSelection_::select_path(Php::Parameters &parameters)
{
	std::string param_path = parameters[0];
	GtkTreePath *path = gtk_tree_path_new_from_string(param_path.c_str());

	gtk_tree_selection_select_path (GTK_TREE_SELECTION(instance), path);

}

void GtkTreeSelection_::unselect_path(Php::Parameters &parameters)
{
	std::string param_path = parameters[0];
	GtkTreePath *path = gtk_tree_path_new_from_string(param_path.c_str());

	gtk_tree_selection_unselect_path (GTK_TREE_SELECTION(instance), path);

}

Php::Value GtkTreeSelection_::path_is_selected(Php::Parameters &parameters)
{
	std::string param_path = parameters[0];
	GtkTreePath *path = gtk_tree_path_new_from_string(param_path.c_str());

	gboolean ret = gtk_tree_selection_path_is_selected (GTK_TREE_SELECTION(instance), path);

	return ret;
}

void GtkTreeSelection_::select_iter(Php::Parameters &parameters)
{
	Php::Value object_iter = parameters[0];
	GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
	GtkTreeIter iter = phpgtk_iter->get_instance();
	
	gtk_tree_selection_select_iter (GTK_TREE_SELECTION(instance), &iter);

}

void GtkTreeSelection_::unselect_iter(Php::Parameters &parameters)
{
	Php::Value object_iter = parameters[0];
	GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
	GtkTreeIter iter = phpgtk_iter->get_instance();

	gtk_tree_selection_unselect_iter (GTK_TREE_SELECTION(instance), &iter);

}

Php::Value GtkTreeSelection_::iter_is_selected(Php::Parameters &parameters)
{
	Php::Value object_iter = parameters[0];
	GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
	GtkTreeIter iter = phpgtk_iter->get_instance();

	gboolean ret = gtk_tree_selection_iter_is_selected (GTK_TREE_SELECTION(instance), &iter);

	return ret;
}

void GtkTreeSelection_::select_all()
{
	gtk_tree_selection_select_all (GTK_TREE_SELECTION(instance));

}

void GtkTreeSelection_::unselect_all()
{
	gtk_tree_selection_unselect_all (GTK_TREE_SELECTION(instance));

}

void GtkTreeSelection_::unselect_range(Php::Parameters &parameters)
{
	std::string param_start_path = parameters[0];
	GtkTreePath *start_path = gtk_tree_path_new_from_string(param_start_path.c_str());

	std::string param_end_path = parameters[0];
	GtkTreePath *end_path = gtk_tree_path_new_from_string(param_end_path.c_str());

	gtk_tree_selection_unselect_range (GTK_TREE_SELECTION(instance), start_path, end_path);

}

